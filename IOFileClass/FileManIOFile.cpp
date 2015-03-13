/**
 * @file FileManIOFile.cpp
 * @brief FileManIOFile class definitions
 * @author manzerbredes
 * @date 9 Mars 2015
 *
 * Contain all definitions of FileManIOFile class.
 *
 */


#include "FileManIOFile.hpp"

//Constructor with filename
FileManIOFile::FileManIOFile(std::string filename){
    this->filename=filename;
    this->readable=false;
    this->data="";
    this->key;
}

//Destructor
FileManIOFile::~FileManIOFile(){
}



//Read the filename with a key
void FileManIOFile::read(std::string key){

    //create file object
    std::ifstream file;

    //Clear data
    this->data.clear();

    //Open file
    file.open (this->filename, std::ios::in | std::ios::binary);

    //Get MD5 of decrypted data
    byte fileMD5[16];
    file.read((char*) fileMD5, sizeof(fileMD5));

    //Read all data
    char car;
    file.read(&car, sizeof(car));

    while(file){
        this->data+=car,
        file.read(&car, sizeof(car));

    }

    //Decrypt data
    this->data=this->aes.decrypt(key, this->data);

    //Get current MD5 of decrypted data
    byte currentMD5[16];
    this->hash.getMD5_128(this->data, currentMD5, sizeof(currentMD5));

    //Compare the 2 MD5 to find if file is fully decrypted
    if(this->hash.compareDigest(fileMD5, currentMD5, sizeof(currentMD5))){
        //Set readable
        this->readable=true;
        //Save the key
        this->hash.getSHA_256(key, this->key, 32);
    }
    else{
        this->readable=false;
    }

    //Close file
    file.close();


}



//Write file with key
void FileManIOFile::write(std::string key,std::string data){

    std::string dataEncrypted;

    dataEncrypted=this->aes.encrypt(key, data);

    this->writeRoutine(data, dataEncrypted);


}

//Write file without key
void FileManIOFile::write(std::string data){
    if(not(this->readable)){
        std::cout << "Can't write data without key (read it before) !" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    std::string dataEncrypted;

    dataEncrypted=this->aes.encrypt(this->key, data);
    this->writeRoutine(data, dataEncrypted);


}



//Get readable attribute
bool FileManIOFile::isReadable(){
    return this->readable;
}



//Write file
void FileManIOFile::writeRoutine(std::string data, std::string dataEncrypted){

    //Save MD5 of decrypted data
    byte digest[16];
    this->hash.getMD5_128(data, digest, sizeof(digest));

    //Create file instance
    std::ofstream file;

    //Open it
    file.open(this->filename, std::ios::out | std::ios::binary);

    //Write MD5 on 16 first bytes
    file.write((char *) digest,sizeof(digest));

    //Write data
    file.write(dataEncrypted.c_str(), dataEncrypted.size());

    //Close file
    file.close();

    //Save data to attribute
    this->data=data;
}



//Get data
std::string FileManIOFile::getData(){
    return this->data;
}
