
#pragma once

#ifndef TEXTURE_HOLDER_H
#define TEXTURE_HOLDER_H
#include<SFML/Graphics.hpp>
#include <bits/stdc++.h>



using namespace sf;
using namespace std;

class TextureHolder{
    private:
        static TextureHolder* instance;
        map<String, Texture> textures;

    public:
        TextureHolder();
        static Texture& getTexture(String name);
        
};


#endif
