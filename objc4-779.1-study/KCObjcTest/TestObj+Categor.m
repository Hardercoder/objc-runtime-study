//
//  TestObj+Categor.m
//  KCObjcTest
//
//  Created by apple on 2020/3/12.
//

#import "TestObj+Categor.h"
#import <objc/runtime.h>

@implementation TestObj (Categor)
- (void)setCatName:(NSString *)catName {
    objc_setAssociatedObject(self, @selector(catName), catName, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

- (NSString *)catName {
    return objc_getAssociatedObject(self, @selector(catName));
}
@end
