//
//  WiFiBaseManager.h
//  WiFiConnetSDK
//
//  Created by Albert on 2020/5/12.
//  Copyright © 2020 Coder_zzz. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "HttpRequest.h"

#define WIFI_START_ORDER    @"FACEAA00"


NS_ASSUME_NONNULL_BEGIN

//网络请求回调
/**
 成功:
 sucess为true
 responseObject为返回结果
 注意: 需要判断code==0, 才能表示此次请求成功
 
 失败:
 sucess为false
 responseObject 为error
 */


typedef enum : NSUInteger {
    WifiStateConnectSuccess,// 设备连接成功，仅当ESP配网模式
    WifiStateTransferComplete,// 设备传输数据完成，仅当ESP配网模式
    WifiStateLinking,//配网中
    WifiStateLinkComplete,// 配网成功
    WifiStateLinkTimeout,// 配网超时
} WifiState;

typedef void(^RequestCallback )(BOOL sucess, id responseObject);
//配网状态回调
typedef void(^ResultCallback)(CGFloat progress, id resultObject);
//wifi状态回调
typedef void(^WiFiCallback)(WifiState wifistate);

@interface WiFiBaseManager : NSObject

/// 联网最大时长(默认60s)
@property (nonatomic, assign) NSInteger countTimer;
//配网状态回调
@property (nonatomic, strong) ResultCallback resultCallback;
//wifi状态回调
@property (nonatomic, strong) WiFiCallback wifiCallback;
//mark
@property (nonatomic, strong) NSString *mark;
//轮询定时器
@property (nonatomic, strong) NSTimer *timer;

/// 初始化
+ (instancetype)shareManager;

/// 配置apikey
/// @param apikey apikey
- (void)configureApiKey:(NSString *)apikey;

/// 获取mark
/// @param location  定位信息(
///     lat: 纬度
///     long:经度
///     city:城市
///     district: 区域
///     province:省份
///     street:街道
/// )
/// @param productType 产品类型
/// @param callback 回调
- (void)requestMarkWithLocation:(NSDictionary*)location productType:(NSString*)productType  callback:(RequestCallback)callback;

/// 配网
/// @param ssid WiFi名称
/// @param pwd WiFi密码
/// @param mark mark
- (void)connectWithSSID:(NSString *)ssid password:(NSString *)pwd mark:(NSString*)mark;

/// 开始轮询获取配网状态, 在resultCallback回传(无需调用)
- (void)startTimer;

//配网成功或失败后续操作(无需调用)
- (void)mangeOpereation;

//手动停止配网
- (void)stopLinkOpereation;
@end

NS_ASSUME_NONNULL_END
