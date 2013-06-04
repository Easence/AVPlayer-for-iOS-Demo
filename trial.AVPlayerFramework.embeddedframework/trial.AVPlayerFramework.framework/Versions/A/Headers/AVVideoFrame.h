//
//  AVVideoFrame.h
//  AVPlayer
//
//  Created by apple on 13-5-19.
//  Copyright (c) 2013年 iMoreApp Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

typedef enum {
    AVMediaFrameTypeAudio,
    AVMediaFrameTypeVideo,
    AVMediaFrameTypeSubtitle

} AVMediaFrameType;


typedef enum {
    AVVideoFrameFormatRGB,
    AVVideoFrameFormatYUV

} AVVideoFrameFormat;


@interface AVMovieFrame : NSObject
@property (nonatomic) AVMediaFrameType type;
@end

@interface AVVideoFrame : AVMovieFrame
@property (nonatomic) AVVideoFrameFormat format;
@property (nonatomic) NSUInteger width;
@property (nonatomic) NSUInteger height;
+ (instancetype)frameWithAVFrame:(void *)frame format:(AVVideoFrameFormat)fmt;
@end

@interface AVVideoFrameRGB : AVVideoFrame
@property (nonatomic) NSUInteger linesize;
@property (nonatomic, strong) NSData *rgb;
- (UIImage *) asImage;
@end

@interface AVVideoFrameYUV : AVVideoFrame
@property (nonatomic, strong) NSData *luma;
@property (nonatomic, strong) NSData *chromaB;
@property (nonatomic, strong) NSData *chromaR;
@end
