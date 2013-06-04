//
//  AVPlayerViewController.h
//  AVPlayer
//
//  Created by apple on 13-5-22.
//  Copyright (c) 2013年 iMoreApp Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AVMovieGLView.h"
#import "AVPlayerController.h"

@interface AVPlayerViewController : UIViewController

// audio or video file path (local or network file path)
@property (nonatomic, strong) NSString *mediaPath;

// required saving progress info, you can save progress here.
@property (nonatomic, copy) void (^saveProgress)(AVPlayerController *player);

// did load video successfully callback.
@property (nonatomic, copy) void (^didLoadVideo)(AVPlayerController *player);

// get start playback time (>= 0 and <= media duration).
// if the property is nil, player will start playback from begining.
// the callback returns a float number value or nil.
@property (nonatomic, copy) NSNumber* (^getStartTime)(NSString *path);

@end
