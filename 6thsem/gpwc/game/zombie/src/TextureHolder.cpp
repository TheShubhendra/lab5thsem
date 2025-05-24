#include "TextureHolder.h"
#include<assert.h>

TextureHolder* TextureHolder::instance = nullptr;

TextureHolder::TextureHolder(){
    assert(instance == nullptr);
    instance = this;
};

Texture& TextureHolder::getTexture(String file){
    auto& m = instance->textures;

    auto texture = m.find(file);

    if(texture != m.end()){
        return texture->second;
    }

    auto& text = m[file];

    text.loadFromFile(file);

    return text;

    
};