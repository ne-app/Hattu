#! /bin/zsh

sudo apt update -y
sudo apt install libwxgtk3.2-dev -y

export WX_CONFIG=/usr/include/wx-3.2

b2 --j8 libs/ui/build/ cxxflags=-std=c++0x
b2 --j8 libs/ui/test/ cxxflags=-std=c++0x
b2 --j8 libs/ui/example/ cxxflags=-std=c++0x
b2 --j8 libs/ui/example/cpp11/ cxxflags=-std=c++0x
