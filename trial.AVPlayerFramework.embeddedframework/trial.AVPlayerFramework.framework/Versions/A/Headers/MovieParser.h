//
//  MovieParser.h
//  AVPlayer
//
//  Created by apple on 13-5-28.
//  Copyright (c) 2013年 iMoreApp Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MovieParser : NSObject

@property (nonatomic, readonly) NSString *path;
@property (readonly, nonatomic) NSTimeInterval duration;
@property (readonly, nonatomic) NSUInteger frameWidth;
@property (readonly, nonatomic) NSUInteger frameHeight;

- (BOOL) open: (NSString *) path;
- (BOOL) hasVideo;
- (BOOL) hasAudio;

- (void) seek: (NSTimeInterval) seconds;
- (NSArray *) decodeFrames: (int) totalFrameCount; // 

@end
