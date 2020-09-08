//
//  DMBluetoothManager.h
//  DMHome
//
//  Created by Albert on 2020/3/18.
//  Copyright © 2020 Coder_zzz. All rights reserved.
//
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreBluetooth/CoreBluetooth.h>


NS_ASSUME_NONNULL_BEGIN

@interface BluetoothModel : NSObject
    @property(nonatomic, strong) CBPeripheral *peripheral;
    @property(nonatomic, strong) NSDictionary<NSString *,id> *advertisementData;
    @property(nonatomic, strong) NSNumber *RSSI;
@end

@class DMBluetoothManager;

@protocol DMBluetoothManagerDelegate <NSObject>

@optional
// 获取设备,会调用多次，需要先调用- (void)startScanDevices;
- (void)manager:(DMBluetoothManager *_Nullable)manager didDiscoverDeveice:(nonnull BluetoothModel *)peripheral error:(nullable NSError *)error;

// 连接某一台设备是否成功的结果，需要先调用- (void)conect:(CBPeripheral *)peripheral;
- (void)manager:(DMBluetoothManager *_Nonnull)manager connectedDevice:(nonnull CBPeripheral *)peripheral state:(BOOL)state;

// 设备更新
- (void)manager:(DMBluetoothManager *_Nullable)manager didUpdateValueForCharacteristic:(nonnull CBCharacteristic *)characteristic receiveData:(NSData *_Nullable)receiveData error:(nullable NSError *)error;

@end

@interface DMBluetoothManager : NSObject
@property (nonatomic, weak, nullable) id <DMBluetoothManagerDelegate> delegate;

// 初始化蓝牙
+ (instancetype _Nonnull )shareManager;

// 开始扫描,prefix: 只查找某一个前缀开头的设备,传nil默认扫描所有
- (void)startScanDevicesHasNamePrefix:(NSString *_Nullable)nameprefix hideAlert:(BOOL)hide;

// 结束扫描
- (void)stopScanDevices;

// 连接某一台设备
- (void)conect:(CBPeripheral *_Nonnull)peripheral ;

// 判断获取某一台设备是否在线
- (BOOL)isOnLine:(CBPeripheral *_Nonnull)peripheral ServiceUUID:(NSString *_Nonnull)ServiceUUID;

// 断开某一台设备
- (void)disconect:(CBPeripheral *_Nullable)peripheral;

@end

NS_ASSUME_NONNULL_END
