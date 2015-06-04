//
//  StarTexture.cpp
//  StarEngine
//
//  Created by sungwoo choi on 8/24/12.
//  Copyright (c) 2012 SungLab. All rights reserved.
//

#include "StarTexture.h"
#ifdef IOS
#import <UIKit/UIKit.h>
//#elif MAC
//#import <Cocoa/Cocoa.h>
#endif

//#ifdef MAC
//#import <Cocoa/Cocoa.h>
//#endif

StarTexture::StarTexture(unsigned int texture_number)
{
    texture = new Texture[texture_number];
    
//    starLOG("is it emphy? %d\n", texture_number);
}

#ifdef IOS
void StarTexture::createTEXTURE_IOS(NSString *filename, unsigned int texture_id)
{
//	CGImageRef image;
//	CGContextRef context;
//	GLubyte *imageData;
//
//	image = [UIImage imageNamed:filename].CGImage;
//	texture[texture_id].texture_width= CGImageGetWidth(image);
//	texture[texture_id].texture_height = CGImageGetHeight(image);
//
//	if(image)
//	{
//        
//		imageData = (GLubyte *) malloc(texture[texture_id].texture_width * texture[texture_id].texture_height * 4);
//		// Uses the bitmatp creation function provided by the Core Graphics framework. 
//		context = CGBitmapContextCreate(image, texture[texture_id].texture_width, texture[texture_id].texture_height,  CGImageGetBitsPerComponent(image),texture[texture_id].texture_width,* 4,
//		CGImageGetColorSpace(image), kCGImageAlphaPremultipliedLast	);
//		// After you create the context, you can draw the sprite image to the context.
//		CGContextDrawImage(context, CGRectMake(0.0, 0.0, (CGFloat)texture[texture_id].texture_width, (CGFloat)texture[texture_id].texture_height), image);
//		// You don't need the context at this point, so you need to release it to avoid memory leaks.
//		CGContextRelease(context);
//
//		glGenTextures(1, &texture[texture_id].texture_id);
//		glBindTexture(GL_TEXTURE_2D, texture[texture_id].texture_id);
//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture[texture_id].texture_width, texture[texture_id].texture_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);
//		free(imageData);
//
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//
//	}
}

#elif ANDROID
//
//void StarTexture::createTEXTURE_ANDROID( void* array, unsigned int texture_width, unsigned int texture_height, unsigned int texture_id)
//{
//	
//	texture[texture_id].texture_width  = texture_width;
//	texture[texture_id].texture_height = texture_height;
//
//	glGenTextures(1, &texture[texture_id].texture_id);
//	glBindTexture(GL_TEXTURE_2D, texture[texture_id].texture_id);
//
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture_width, texture_height, 0,GL_RGBA, GL_UNSIGNED_BYTE, array); 
//
//
//}
#endif

// it should know what it is the number of User defined texture ID ( userDefined TexID != computerDefined TexID);
void StarTexture::createTEXTURE_DATA( void* data, unsigned int camera_width, unsigned int camera_height, unsigned int texture_id, bool alpha)
{
    
	texture[texture_id].texture_width  = camera_width;
	texture[texture_id].texture_height = camera_height;

    if (!texture[texture_id].texture_id)
    glGenTextures(1, &texture[texture_id].texture_id);
    
    glBindTexture(GL_TEXTURE_2D, texture[texture_id].texture_id);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
if(alpha)
{
#ifdef ANDROID
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, camera_width, camera_height, 0,GL_RGBA, GL_UNSIGNED_BYTE,  0);
    glTexSubImage2D(GL_TEXTURE_2D, 0,0,0, camera_width, camera_height, GL_RGBA, GL_UNSIGNED_BYTE, data);
#elif IOS
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, camera_width, camera_height, 0,GL_RGBA, GL_UNSIGNED_BYTE, 0);
    glTexSubImage2D(GL_TEXTURE_2D, 0,0,0, camera_width, camera_height, GL_RGBA, GL_UNSIGNED_BYTE, data);
#elif MAC
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, camera_width, camera_height, 0,GL_RGBA, GL_UNSIGNED_BYTE, 0);
    glTexSubImage2D(GL_TEXTURE_2D, 0,0,0, camera_width, camera_height, GL_RGBA, GL_UNSIGNED_BYTE, data);
#endif
}
else
{
#ifdef ANDROID
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, camera_width, camera_height, 0,GL_RGB, GL_UNSIGNED_BYTE,  0);
    glTexSubImage2D(GL_TEXTURE_2D, 0,0,0, camera_width, camera_height, GL_RGB, GL_UNSIGNED_BYTE, data);
#elif IOS
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, camera_width, camera_height, 0,GL_RGB, GL_UNSIGNED_BYTE, 0);
    glTexSubImage2D(GL_TEXTURE_2D, 0,0,0, camera_width, camera_height, GL_RGB, GL_UNSIGNED_BYTE, data);
#elif MAC
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, camera_width, camera_height, 0,GL_RGB, GL_UNSIGNED_BYTE, 0);
    glTexSubImage2D(GL_TEXTURE_2D, 0,0,0, camera_width, camera_height, GL_RGB, GL_UNSIGNED_BYTE, data);
#endif
}
    
//    glEnable(GL_TEXTURE_2D);
}

void StarTexture::createTEXTURE_RTT(unsigned int texture_width, unsigned int texture_height, unsigned int texture_id,bool resize)
{

	texture[texture_id].texture_width = texture_width;
	texture[texture_id].texture_height = texture_height;
    
  if(!resize)
  {
      glGenTextures(1, &texture[texture_id].texture_id);
      glBindTexture(GL_TEXTURE_2D,texture[texture_id].texture_id);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//      glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//      glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture_width, texture_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
      glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture[texture_id].texture_id, 0);
  }
  else
  {
//      glGenTextures(1, &texture[texture_id].texture_id);
//      glBindTexture(GL_TEXTURE_2D,texture[texture_id].texture_id);
//      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
      glBindTexture(GL_TEXTURE_2D,texture[texture_id].texture_id);
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture_width, texture_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
  }
    
}

Texture* StarTexture::getTEXTURE(unsigned int texture_id)
{
    return &texture[texture_id];
}

void StarTexture::bindTEXTURE(unsigned int texture_unit, unsigned int texture_id)
{
//    if(texture_unit)
    glActiveTexture(texture_unit);
    glBindTexture( GL_TEXTURE_2D, texture[texture_id].texture_id);
}

void StarTexture::deleteTEXTURE(unsigned int texture_id)
{
	if(texture[texture_id].texture_id!=0)
	{
        texture[texture_id].texture_id = 0;
        texture[texture_id].texture_width = 0;
        texture[texture_id].texture_height = 0;
		glDeleteTextures(1, &texture[texture_id].texture_id);
	}
}
//#ifndef ANROID
//StarImage* StarTexture::createImage(const char* filepathname,bool flip90degree)
//{
//
//    NSString *filepathString = [[NSString alloc] initWithUTF8String:filepathname];
//#ifdef IOS
//    UIImage* imageClass = [[UIImage alloc] initWithContentsOfFile:filepathString];
//#elif MAC
//    NSImage *nsimage = [[NSImage alloc] initWithContentsOfFile: filepathString];
//    NSBitmapImageRep *imageClass = [[NSBitmapImageRep alloc] initWithData:[nsimage TIFFRepresentation]];
//    [nsimage release];
//#endif
//    
//    CGImageRef cgImage = imageClass.CGImage;
//    if (!cgImage)
//    {
//        [filepathString release];
//        [imageClass release];
//        return NULL;
//    }
//    StarImage* image = (StarImage*)malloc(sizeof(StarImage));
//    image->width= (float)CGImageGetWidth(cgImage);
//    image->height = (float)CGImageGetHeight(cgImage);
//    image->rowByteSize = image->width * 4;
//    image->data = (char*)malloc(image->height * image->rowByteSize);
//    image->format = GL_RGBA;
//    image->type = GL_UNSIGNED_BYTE;
//    
//    CGContextRef context = CGBitmapContextCreate(image->data, image->width, image->height, 8, image->rowByteSize, CGImageGetColorSpace(cgImage), kCGImageAlphaNoneSkipLast);
//    CGContextSetBlendMode(context, kCGBlendModeCopy);
//    if(flip90degree)
//    {
//        CGContextTranslateCTM(context, 0.0, image->height);
//        CGContextScaleCTM(context, 1.0, -1.0);
//    }
//    CGContextDrawImage(context, CGRectMake(0.0, 0.0, image->width, image->height), cgImage);
//    CGContextRelease(context);
//    
//    if(NULL == image->data)
//    {
//        [filepathString release];
//        [imageClass release];
//        
//       deleteImage(image);
//        return NULL;
//    }
//    
//    [filepathString release];
//    [imageClass release];	
//    
//    return image;
//}
//void StarTexture::deleteImage(StarImage* image)
//{
//    free(image->data);
//    free(image);
//}
//#endif