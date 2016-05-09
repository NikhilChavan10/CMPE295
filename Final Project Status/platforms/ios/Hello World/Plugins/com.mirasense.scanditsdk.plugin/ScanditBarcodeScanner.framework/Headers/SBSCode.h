//
//  SBSCode.h
//  BarcodeScanner
//
//  Created by Marco Biasini on 20/05/15.
//  Copyright (c) 2015 Scandit AG. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKit.h>

#import "SBSCommon.h"

/**
 * \brief Quadrilateral represented by 4 corners
 *
 *
 */
typedef struct  {
    /**
     * \brief The top-left corner
     */
	CGPoint topLeft;
    /**
     * \brief The top-right corner
     */
	CGPoint topRight;
    /**
     * \brief The bottom-right corner
     */
	CGPoint bottomRight;
    /**
     * \brief The bottom-left corner
     */
	CGPoint bottomLeft;
} SBSQuadrilateral;



/**
 * \brief Enumerates the symbologies supported by Scandit Barcode Scanner
 *
 * Some of these symbologies are only available in the Professional and Enterprise Packages.
 */
SBS_ENUM_BEGIN(SBSSymbology) {
    /**
     * \brief Sentinel value to represent an unknown symbology
     */
    SBSSymbologyUnknown = 0x0000000,
    /** 
     * EAN-13 1D barcode symbology.
     */
    SBSSymbologyEAN13 = 0x0000001,
    /** 
     * UPC-12/UPC-A 1D barcode symbology.
     */
    SBSSymbologyUPC12 = 0x0000004,
    /** 
     * UPC-E 1D barcode symbology.
     */
    SBSSymbologyUPCE = 0x0000008,
    /** 
     * Code 39 barcode symbology. Only available in the Professional and Enterprise Packages.
     */
    SBSSymbologyCode39 = 0x0000020,
    /**
     * PDF417 barcode symbology. Only available in the Professional and Enterprise Packages. 
     */
    SBSSymbologyPDF417 = 0x0000400,
    /**
     * Data Matrix 2D barcode symbology. Only available in the Professional and Enterprise Packages.
     */
    SBSSymbologyDatamatrix = 0x0000200,
    /**
     * QR Code 2D barcode symbology. 
     */
    SBSSymbologyQR = 0x0000100,
    /**
     * Interleaved-Two-of-Five (ITF) 1D barcode symbology. Only available in the Professional and 
     * Enterprise Packages.
     */
    SBSSymbologyITF = 0x0000080,
    /**
     * Code 128 1D barcode symbology, including GS1-Code128. Only available in the Professional and
     * Enterprise Packages. 
     */
    SBSSymbologyCode128 = 0x0000010,
    /** 
     * Code 93 barcode symbology. Only available in the Professional and Enterprise Packages. 
     */
    SBSSymbologyCode93 = 0x0000040,
    /** 
     * MSI Plessey 1D barcode symbology. Only available in the Professional and Enterprise Packages. 
     */
    SBSSymbologyMSIPlessey = 0x0000800,
    /** 
     * GS1 DataBar 14 1D barcode symbology. Only available in the Professional and Enterprise Packages.
     */
    SBSSymbologyGS1Databar = 0x0001000,
    /** 
     * GS1 DataBar Expanded 1D barcode symbology. Only available in the Professional and Enterprise Packages.
     */
    SBSSymbologyGS1DatabarExpanded = 0x0002000,
    /** 
     * Codabar 1D barcode symbology. Only available in the Professional and Enterprise Packages. 
     */
    SBSSymbologyCodabar = 0x0004000,
    /** 
     * EAN-8 1D barcode symbology.
     */
    SBSSymbologyEAN8 = 0x0000002,
    /** 
     * Aztec Code 2D barcode symbology. Only available in the Professional and Enterprise Packages.
     */
    SBSSymbologyAztec = 0x0008000,
    /**
     * Two-digit add-on for UPC and EAN codes.
     *
     * In order to scan two-digit add-on codes, at least one of these symbologies must be activated
     * as well: \ref SBSSymbologyEAN13, \ref SBSSymbologyUPC12, \ref SBSSymbologyUPCE, or 
     * \ref SBSSymbologyEAN8 and the maximum number of codes per frame has to be set to at least 2.
     *
     * Only available in the Professional and Enterprise Packages.
     */
    SBSSymbologyTwoDigitAddOn = 0x0010000,
    /**
     * Five-digit add-on for UPC and EAN codes.
     *
     * In order to scan five-digit add-on codes, at least one of these symbologies must be activated
     * as well: \ref SBSSymbologyEAN13, \ref SBSSymbologyUPC12, \ref SBSSymbologyUPCE, or 
     * \ref SBSSymbologyEAN8 and the maximum number of codes per frame has to be set to at least 2.
     *
     * Only available in the Professional and Enterprise Packages.
     */
    SBSSymbologyFiveDigitAddOn = 0x0020000,
    /**
     * Code 11 1D barcode symbology
     *
     * Only available in the Professional and Enterprise Packages.
     */
    SBSSymbologyCode11 = 0x0080000,
    /**
     * MaxiCode 2D barcode symbology
     *
     * Only available in the Professional and Enterprise Packages.
     */
    SBSSymbologyMaxiCode = 0x0040000,
    
    /**
     * GS1 DataBar Limited 1D barcode symbology
     *
     * Only available in the Professional and Enterprise Packages.
     */
    SBSSymbologyGS1DatabarLimited = 0x0100000,
    /**
     * Code25 1D barcode symbology
     *
     * Also known as 'Industrial 2 of 5', 'Standard 2 of 5' or 'Discrete 2 of 5'. 
     *
     * Only available in Professional and Enterprise Packages.
     */
    SBSSymbologyCode25            = 0x0200000
} SBS_ENUM_END(SBSSymbology);


/**
 * \brief Represents a recognized/localized barcode/2D code.
 *
 * The SBSCode class represents a  barcode, or 2D code that has been localized or recognized
 * by the barcode recognition engine.
 */
@interface SBSCode : NSObject

/**
 * \brief The symbology of the barcode as a string, including GS1 data carrier states
 *
 * This property is set to one of the following values:
 *
 * \c "EAN8", \c "EAN13", \c "UPC12", \c "UPCE", \c "CODE128", \c "GS1-128", 
 * \c "CODE39", \c "CODE93", \c "ITF", \c "MSI", \c "CODABAR", \c "GS1-DATABAR", 
 * \c "GS1-DATABAR-EXPANDED", \c "QR", \c "GS1-QR", \c "DATAMATRIX", 
 * \c "GS1-DATAMATRIX", \c "PDF417", \c "TWO-DIGIT-ADD-ON", \c "FIVE-DIGIT-ADD-ON",
 * \c "AZTEC", \c "MAXICODE", \c "GS1-DATABAR-LIMITED", \c "CODE11", \c "UNKNOWN".
 *
 * Codes for which \ref SBSCode#isRecognized is NO, \c "UNKNOWN" is returned.
 */
@property (nonnull, nonatomic, readonly) NSString *symbologyString;

/**
 * \brief The symbology name of the barcode as a string.
 *
 * \return Lower-case symbology name. Codes for which \ref SBSCode#isRecognized is 
       NO, \c "unknown" is returned. In contrast to \ref SBSCode#symbologyString, the returned
 *     symbology does not contain any information on whether the code is a GS1 data carrier, use
 *     \ref SBSCode#isGs1DataCarrier for that.
 *
 * \since 4.10.0
 */
@property (nonnull, nonatomic, readonly) NSString * symbologyName;

/**
 * \brief Returns the symbology of a recognized barcode
 *
 * Codes for which \ref SBSCode#isRecognized is NO return \ref SBSSymbologyUnknown.
 */
@property (nonatomic, readonly) SBSSymbology symbology;


/**
 *  \brief The data contained in the barcode/2D code, e.g. the 13 digit number
 *     of a EAN-13 code.
 *
 * For some types of barcodes/2D codes (for example DATAMATRIX, AZTEC, PDF417), the 
 * data string may contain non-printable characters and nul-bytes in the middle of 
 * the string. SBSCode#data may be nil in these cases. Use \ref SBSCode#rawData if 
 * your application scans these types of codes and you are expecting binary/non-
 * printable data.
 */
@property (nullable, nonatomic, readonly) NSString *data;

/**
 * \brief The raw byte data contained in the barcode.
 *
 * Use this method in case you are encoding binary data in barcodes\2D codes that 
 * can not be represented as UTF-8 strings. For codes that are localized but not 
 * recognized, nil is returned.
 */
@property (nullable, nonatomic, readonly) NSData *rawData;

/**
 * \brief Whether the code was completely recognized.
 *
 * This property is true for barcodes that were completely recognized and false for 
 * codes that were localized but not recognized. For codes returned by 
 * \ref SBSScanSession#newlyRecognizedCodes and
 * \ref SBSScanSession#allRecognizedCodes \ref isRecognized always returns
 * YES, for codes returned by \ref SBSScanSession#newlyLocalizedCodes
 * \ref isRecognized always returns NO.
 */
@property (nonatomic, readonly) BOOL isRecognized;

/**
 * \brief The location of the code in the image.
 *
 * The location is returned as a a polygon with 4 corners. The corners are in the 
 * coordinate system of the raw preview image. In order to be displayed they must be 
 * transformed to the coordinate system of the view. The meaning of the values of topLeft, 
 * topRight etc is such that the topLeft point corresponds to the top-left corner of the 
 * barcode  regardless of how it is oriented in the image.
 *
 * \see SBSBarcodePicker#convertPointToPickerCoordinates:
 */
@property (nonatomic, readonly) SBSQuadrilateral location;

/**
 * \brief Whether the code is a GS1 data carrier
 *
 * \return True if the code is a GS1 data carrier, false if not. False is returned for codes
 *     that have only been localized but not recognized.
 *
 * \since 4.10.2
 */
@property (nonatomic, readonly) BOOL isGs1DataCarrier;

/**
 * \brief The symbol count of this barcode
 *
 * Use this value to determine the symbol count of a particular barcode, e.g. to configure 
 * the active symbol counts. For localized, but not recognized barcodes as well as 2d codes 
 * this property is set to -1.
 */
@property (nonatomic, readonly) int symbolCount;


@end
