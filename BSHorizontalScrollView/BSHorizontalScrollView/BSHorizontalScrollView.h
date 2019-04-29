//
//  BSHorizontalScrollView.h
//  lunboScrollView
//
//  Created by 董志玮 on 2019/4/26.
//  Copyright © 2019 chao. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
typedef void (^scrollViewDidEndDeceleratingBlock)(UIScrollView *svDidEndDeceler);
typedef void (^scrollViewDidEndScrollingAnimation)(UIScrollView *svDidEndScoAni);
typedef void (^scrollViewDidScroll)(UIScrollView *svDidScroll);
@protocol BSScrollViewDidSelectDelegate <NSObject>
- (void)selectedAtIndex:(int)atIndex;
@end

@interface BSHorizontalScrollView : UIView
@property (strong, nonatomic) UIView *scrollViewWithPaging;
@property (strong, nonatomic) UIPageControl *pageControl;
@property (strong, nonatomic) UIScrollView *scrollView;

@property (assign, nonatomic) CGRect viewRect;
@property (nonatomic,strong) NSMutableArray *imageArray;
@property (nullable,nonatomic,strong) NSTimer *timer;
@property (weak, nonatomic) id<BSScrollViewDidSelectDelegate>delegate;

@property (nonatomic, copy) scrollViewDidEndDeceleratingBlock svDidEndDeceler;
@property (nonatomic, copy) scrollViewDidEndScrollingAnimation svDidEndScoAni;
@property (nonatomic, copy) scrollViewDidScroll svDidScroll;

- (instancetype)initWithViewRect:(CGRect)viewRect bannerImageNameArray:(NSArray *)imageNameArray;
- (void)addTimer;
- (void)invalidateTimer;
@end

NS_ASSUME_NONNULL_END
