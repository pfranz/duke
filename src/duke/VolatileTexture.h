/*
 * VolatileTexture.h
 *
 *  Created on: Dec 22, 2012
 *      Author: Guillaume Chatelet
 */

#ifndef VOLATILETEXTURE_H_
#define VOLATILETEXTURE_H_

#include <duke/imageio/DukeIO.h>
#include <duke/imageio/Attributes.h>
#include <duke/gl/Texture.h>

class IImageReader; // forward decl

struct VolatileTexture {
	VolatileTexture(GLuint type);
	bool load(const char* filename, GLuint minFilter, GLuint magFilter, GLuint wrapMode);
	ScopeBinder<TextureBuffer> use(GLuint dimensionUniformParameter) const;
	Attributes attributes;
	ImageDescription description;
	GLuint minFilter;
	GLuint magFilter;
	GLuint wrapMode;
private:
	std::string loadImage(std::unique_ptr<IImageReader> &&pReader);
	void loadGlTexture(const void* pData);
	SharedTextureBuffer m_pTextureBuffer;
};

#endif /* VOLATILETEXTURE_H_ */
