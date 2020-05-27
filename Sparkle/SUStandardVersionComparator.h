//
//  SUStandardVersionComparator.h
//  Sparkle
//
//  Created by Andy Matuschak on 12/21/07.
//  Copyright 2007 Andy Matuschak. All rights reserved.
//

#ifndef SUSTANDARDVERSIONCOMPARATOR_H
#define SUSTANDARDVERSIONCOMPARATOR_H

#if __has_feature(modules)
@import Foundation;
#else
#import <Foundation/Foundation.h>
#endif
#import "SUExport.h"
#import "SUVersionComparisonProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@class SUAppcastItem;
@class SUHost;

/*!
    Sparkle's default version comparator.

    This comparator is adapted from MacPAD, by Kevin Ballard.
    It's "dumb" in that it does essentially string comparison,
    in components split by character type.
*/
SU_EXPORT @interface SUStandardVersionComparator : NSObject <SUVersionComparison>

/*!
    Initializes a new instance of the standard version comparator.
 */
- (instancetype)init;

/*!
    Returns a singleton instance of the comparator.
 
    It is usually preferred to alloc/init new a comparator instead.
*/
+ (SUStandardVersionComparator *)defaultComparator;

/*!
    Compares version strings through textual analysis.

    See the implementation for more details.
*/
// this is now "private"
- (NSComparisonResult)_compareVersion:(NSString *)versionA toVersion:(NSString *)versionB;

// we use these instead everywhere now
- (NSComparisonResult)cascadeCompare:(SUHost*)host_ appcast:(SUAppcastItem*)item_;
- (NSComparisonResult)cascadeCompare:(SUHost*)host_ updateHost:(SUHost*)uhost_;
- (NSComparisonResult)cascadeCompareAppcast:(SUAppcastItem*)lhs_ appcast:(SUAppcastItem*)rhs_;

@end

NS_ASSUME_NONNULL_END
#endif
