//
//  BusinessSelectionBannerView.h
//  testhorizontalscroll
//
//  Created by 董志玮 on 2019/4/25.
//  Copyright © 2019 董志玮. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
typedef void (^scrollViewBlock)(CGFloat velocity, CGFloat offset);
typedef void (^scrollViewEndDeceleratingBlock)(UIScrollView *scrollView);
@protocol BSScrollViewDidSelectDelegate <NSObject>

- (void)selectedAtIndex:(int)atIndex;

@end


@interface BusinessSelectionBannerView : UIView<UIScrollViewDelegate>

@property (nonatomic, strong) UIScrollView *scrollView;
@property (nonatomic, strong) UIView *scrollViewWithPaging;
@property (strong, nonatomic) UIPageControl *pageControl;

@property (nonatomic, weak) id<BSScrollViewDidSelectDelegate>delegate;
@property (nonatomic, copy) scrollViewBlock svBlock;
@property (nonatomic, copy) scrollViewEndDeceleratingBlock svEndDeceBlock;

@property (assign, nonatomic) int bfScrollIndex;
@property (assign, nonatomic) int imageCount;

@property (strong, nonatomic) NSTimer *timer;

- (instancetype)initWithViewRect:(CGRect)viewRect bannerImageNameArray:(NSArray *)imageNameArray;
- (void)startTimerWithScrollView:(nullable UIScrollView *)scrollView;
- (void)cancelTimer;

@end

NS_ASSUME_NONNULL_END
