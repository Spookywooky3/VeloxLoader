## What is Velox Loader?
Velox Loader is a user authentication application which injects a dll once authed written in c++. It authenticates with an Express.JS/MongoDB backend.

## Requirements
* NodeJS 14.*
* MongoDB
* Poco 1.10.1
* Vcpkg/Conan

## Installation
cd "Velox Backend" && npm install  
vcpkg install POCO  
vcpkg integrate install

## TODO:
* Anti-reversal
* Injection
* DLL Download
