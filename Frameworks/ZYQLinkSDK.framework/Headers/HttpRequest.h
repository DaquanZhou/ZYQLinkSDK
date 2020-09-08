//
//  HttpRequest.h
//  WiFiConnetSDK
//
//  Created by Albert on 2020/5/8.
//  Copyright © 2020 Coder_zzz. All rights reserved.
//

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

typedef void(^successBlock)(NSURLSessionDataTask *request,id responseObject);
typedef void(^errorBlock)(NSURLSessionDataTask *request,NSError *error);

@interface HttpRequest : NSObject

//GET请求
+(void)doGetWithURL:(NSString *)url withParams:(NSDictionary *)params  success:(successBlock)done failure:(errorBlock)fail;
//POST请求
+(void)doPostWithURL:(NSString *)url withParams:(NSDictionary *)params  success:(successBlock)done failure:(errorBlock)fail;

@end

NS_ASSUME_NONNULL_END
