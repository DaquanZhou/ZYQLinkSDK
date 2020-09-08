//
//  NewBleConnectManager.h
//  WiFiConnetSDK
//
//  Created by Albert on 2020/5/13.
//  Copyright © 2020 Coder_zzz. All rights reserved.
//

#import "WiFiBaseManager.h"
#import <CoreBluetooth/CoreBluetooth.h>
#import "DMBluetoothManager.h"


@interface NewBleConnectManager : WiFiBaseManager

@property (nonatomic, strong) DMBluetoothManager *bluetooth;

- (void)connectWithPeripheral:(CBPeripheral*)peripheral;

@end

