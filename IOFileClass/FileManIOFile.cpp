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
#include <iomanip> // This might be necessary

FileManIOFile::FileManIOFile(std::string filename){
    this->filename=filename;
    this->readable=false;
    this->data="";
    this->key;
}
FileManIOFile::~FileManIOFile(){
}


bool FileManIOFile::isReadable(){
    return this->readable;
}


void FileManIOFile::read(std::string key){

    AESCrypt aes;
    HASHCrypt hash;

    std::ifstream file;
    this->data.clear();

    file.open (this->filename, std::ios::in | std::ios::binary);

    byte fileMD5[16];
    file.read((char*) fileMD5, sizeof(fileMD5));

    char car;
    file.read(&car, sizeof(car));

    while(file){
        this->data+=car,
        file.read(&car, sizeof(car));

    }

    this->data=aes.decrypt(key, this->data);

    byte currentMD5[16];
    hash.getMD5_128(this->data, currentMD5, sizeof(currentMD5));

    if(hash.compareDigest(fileMD5, currentMD5, sizeof(currentMD5))){
        this->readable=true;
        hash.getSHA_256(key, this->key, 32);
    }
    else{
        this->readable=false;
    }


    file.close();


}




void FileManIOFile::write(std::string key,std::string data){

    AESCrypt aes;
    HASHCrypt hash;
    std::string dataEncrypted;

    dataEncrypted=aes.encrypt(key, data);


    byte digest[16];
    hash.getMD5_128(data, digest, sizeof(digest));


    std::ofstream file;
    file.open(this->filename, std::ios::out | std::ios::binary);

    file.write((char *) digest,sizeof(digest));


    file.write(dataEncrypted.c_str(), dataEncrypted.size());



    file.close();

    this->data=data;

}

void FileManIOFile::write(std::string data){

    AESCrypt aes;
    HASHCrypt hash;
    std::string dataEncrypted;

    dataEncrypted=aes.encrypt(this->key, data);


    byte digest[16];
    hash.getMD5_128(data, digest, sizeof(digest));


    std::ofstream file;
    file.open(this->filename, std::ios::out | std::ios::binary);

    file.write((char *) digest,sizeof(digest));


    file.write(dataEncrypted.c_str(), dataEncrypted.size());



    file.close();

    this->data=data;

}

std::string FileManIOFile::getData(){
    return this->data;
}
