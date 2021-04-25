/*
Copyright (c) 2017, The Linux Foundation. All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:
    * Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
    copyright notice, this list of conditions and the following
    disclaimer in the documentation and/or other materials provided
    with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
    contributors may be used to endorse or promote products derived
    from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

using namespace std;

#define LTA_MODEL_OFFSET 20
#define LTA_MODEL_LENGTH 4

string get_model_number()
{
    string lta;

    DIR* dirFile = opendir( "/lta-label/" );
    if ( dirFile ) 
    {
        struct dirent* hFile;

        while (( hFile = readdir( dirFile )) != NULL ) 
        {
            // ignore these special files
            if ( !strcmp( hFile->d_name, "."  )) continue;
            if ( !strcmp( hFile->d_name, ".." )) continue;

            // get the model from the file name of the .html file
            if ( strstr( hFile->d_name, ".html" ))
            lta = string(hFile->d_name).substr(LTA_MODEL_OFFSET, LTA_MODEL_LENGTH);
        }
        closedir( dirFile );
    }
    return lta;
}

void vendor_load_properties()
{
    string platform;
    string hardware;
    string device;
    string model;
    
    platform = property_get("ro.board.platform");
    if (platform != ANDROID_TARGET)
    return;

    hardware = property_get("ro.boot.hardware");
    model = get_model_number();
    
    if (hardware == "eagle") {
        if (model == "2403") {
            /* D2403 (Xperia M2 Aqua) */
            property_set("ro.product.model", "Xperia M2 Aqua");
            property_set("ro.product.name", "D2403");
            property_set("ro.product.device", "D2403");
            property_set("ro.build.product", "D2403");
            property_set("ro.build.description", "D2403-user 5.1.1 18.6.A.0.182 1643041205 release-keys");
            property_set("ro.build.fingerprint", "Sony/D2403/D2403:5.1.1/18.6.A.0.182/1643041205:user/release-keys");
            property_set("ro.telephony.default_network", "9");
            property_set("persist.radio.multisim.config", "");
            property_set("telephony.lteOnGsmDevice", "1");
        } else if (model == "2406") {
            /* D2406 (Xperia M2 Aqua USA) */
            property_set("ro.product.model", "Xperia M2 Aqua");
            property_set("ro.product.name", "D2406");
            property_set("ro.product.device", "D2406");
            property_set("ro.build.product", "D2406");
            property_set("ro.build.description", "D2406-user 5.1.1 18.6.A.0.182 1643041205 release-keys");
            property_set("ro.build.fingerprint", "Sony/D2406/D2406:5.1.1/18.6.A.0.182/1643041205:user/release-keys");
            property_set("ro.telephony.default_network", "9");
            property_set("persist.radio.multisim.config", "");
            property_set("telephony.lteOnGsmDevice", "1");
        } else if (model == "2302") {
            /* D2302 (Xperia M2 Dual) */
            property_set("ro.product.model", "Xperia M2 Dual");
            property_set("ro.product.name", "D2302");
            property_set("ro.product.device", "D2302");
            property_set("ro.build.product", "D2302");
            property_set("ro.build.description", "D2302-user 5.1.1 18.6.A.0.182 1643041205 release-keys");
            property_set("ro.build.fingerprint", "Sony/D2302/D2302:5.1.1/18.6.A.0.182/1643041205:user/release-keys");
            property_set("ro.telephony.default_network", "0,1");
            property_set("ro.telephony.ril.config", "simactivation");
            property_set("persist.radio.multisim.config", "dsds");
            property_set("persist.radio.dont_use_dsd", "true");
            property_set("persist.radio.plmn_name_cmp", "1");
        } else if (model == "2305") {
            /* D2305 (Xperia M2 3G) */
            property_set("ro.product.model", "Xperia M2 3G");
            property_set("ro.product.name", "D2305");
            property_set("ro.product.device", "D2305");
            property_set("ro.build.product", "D2305");
            property_set("ro.build.description", "D2305-user 5.1.1 18.6.A.0.182 1643041205 release-keys");
            property_set("ro.build.fingerprint", "Sony/D2305/D2305:5.1.1/18.6.A.0.182/1643041205:user/release-keys");
            property_set("ro.telephony.default_network", "0");
            property_set("persist.radio.multisim.config", "");
        } else if (model == "2306") {
            /* D2306 (Xperia M2 LTE USA) */
            property_set("ro.product.model", "Xperia M2");
            property_set("ro.product.name", "D2306");
            property_set("ro.product.device", "D2306");
            property_set("ro.build.product", "D2306");
            property_set("ro.build.description", "D2306-user 5.1.1 18.6.A.0.182 1643041205 release-keys");
            property_set("ro.build.fingerprint", "Sony/D2306/D2306:5.1.1/18.6.A.0.182/1643041205:user/release-keys");
            property_set("ro.telephony.default_network", "9");
            property_set("persist.radio.multisim.config", "");
            property_set("telephony.lteOnGsmDevice", "1");
        } else {
            /* D2303 (Xperia M2 LTE) */
            property_set("ro.product.model", "Xperia M2");
            property_set("ro.product.name", "D2303");
            property_set("ro.product.device", "D2303");
            property_set("ro.build.product", "D2303");
            property_set("ro.build.description", "D2303-user 5.1.1 18.6.A.0.182 1643041205 release-keys");
            property_set("ro.build.fingerprint", "Sony/D2303/D2303:5.1.1/18.6.A.0.182/1643041205:user/release-keys");
            property_set("ro.telephony.default_network", "9");
            property_set("persist.radio.multisim.config", "");
            property_set("telephony.lteOnGsmDevice", "1");
        }
    } else if (hardware == "flamingo") {
        if (model == "2202") {
            /* D2202 (Xperia E3 3G) */
            property_set("ro.product.model", "Xperia E3 3G");
            property_set("ro.product.name", "D2202");
            property_set("ro.product.device", "D2202");
            property_set("ro.build.product", "D2202");
            property_set("ro.build.description", "D2202-user 4.4.4 18.5.C.0.25 5n9_bQ release-keys");
            property_set("ro.build.fingerprint", "Sony/D2202/D2202:4.4.4/18.5.C.0.25/5n9_bQ:user/release-keys");
            property_set("ro.telephony.default_network", "0");
            property_set("persist.radio.multisim.config", "");
        } else if (model == "2203") {
            /* D2203 (Xperia E3 LTE) */
            property_set("ro.product.model", "Xperia E3");
            property_set("ro.product.name", "D2203");
            property_set("ro.product.device", "D2203");
            property_set("ro.build.product", "D2203");
            property_set("ro.build.description", "D2203-user 4.4.4 18.5.C.0.25 5n9_bQ release-keys");
            property_set("ro.build.fingerprint", "Sony/D2203/D2203:4.4.4/18.5.C.0.25/5n9_bQ:user/release-keys");
            property_set("ro.telephony.default_network", "9");
            property_set("persist.radio.multisim.config", "");
            property_set("telephony.lteOnGsmDevice", "1");
        } else if (model == "2206") {
            /* D2206 (Xperia E3 LTE) */
            property_set("ro.product.model", "Xperia E3");
            property_set("ro.product.name", "D2206");
            property_set("ro.product.device", "D2206");
            property_set("ro.build.product", "D2206");
            property_set("ro.build.description", "D2206-user 4.4.4 18.5.C.0.25 5n9_bQ release-keys");
            property_set("ro.build.fingerprint", "Sony/D2206/D2206:4.4.4/18.5.C.0.25/5n9_bQ:user/release-keys");
            property_set("ro.telephony.default_network", "9");
            property_set("persist.radio.multisim.config", "");
            property_set("telephony.lteOnGsmDevice", "1");
        } else if (model == "2212") {
            /* D2212 (Xperia E3 Dual) */
            property_set("ro.product.model", "Xperia E3 Dual");
            property_set("ro.product.name", "D2212");
            property_set("ro.product.device", "D2212");
            property_set("ro.build.product", "D2212");
            property_set("ro.build.description", "D2212-user 4.4.4 18.5.C.0.25 5n9_bQ release-keys");
            property_set("ro.build.fingerprint", "Sony/D2212/D2212:4.4.4/18.5.C.0.25/5n9_bQ:user/release-keys");
            property_set("ro.telephony.default_network", "0,1");
            property_set("ro.telephony.ril.config", "simactivation");
            property_set("persist.radio.multisim.config", "dsds");
            property_set("persist.radio.dont_use_dsd", "true");
            property_set("persist.radio.plmn_name_cmp", "1");
         } else if (model == "2243" ) {
            /* D2243 (Xperia E3 LTE) */
            property_set("ro.product.model", "Xperia E3");
            property_set("ro.product.name", "D2243");
            property_set("ro.product.device", "D2243");
            property_set("ro.build.product", "D2243");
            property_set("ro.build.description", "D2243-user 4.4.4 18.5.C.0.25 5n9_bQ release-keys");
            property_set("ro.build.fingerprint", "Sony/D2243/D2243:4.4.4/18.5.C.0.25/5n9_bQ:user/release-keys");
            property_set("ro.telephony.default_network", "9");
            property_set("persist.radio.multisim.config", "");
            property_set("telephony.lteOnGsmDevice", "1");
        } else {
            /* Recovery */
            property_set("ro.product.model", "Xperia E3");
            property_set("ro.product.device", "flamingo");
            property_set("ro.build.product", "flamingo");
        }
    } else if (hardware == "tianchi") {
        if (model == "5303") {
            /* D5303 (Xperia T2 Ultra LTE) */
            property_set("ro.product.model", "Xperia T2 Ultra");
            property_set("ro.product.device", "D5303");
            property_set("ro.build.product", "D5303");
            property_set("ro.build.description", "D5303-user 4.4.3 19.1.1.A.0.165 Wv93Zw release-keys");
            property_set("ro.build.fingerprint", "Sony/D5303/D5303:4.4.3/19.1.1.A.0.165/Wv93Zw:user/release-keys");
            property_set("ro.telephony.default_network", "9");
            property_set("persist.radio.multisim.config", "");
            property_set("telephony.lteOnGsmDevice", "1");
        } else if (model == "5306") {
            /* D5306 (Xperia T2 Ultra LTE) */
            property_set("ro.product.model", "Xperia T2 Ultra");
            property_set("ro.product.device", "D5306");
            property_set("ro.build.product", "D5306");
            property_set("ro.build.description", "D5306-user 4.4.3 19.1.1.A.0.165 Wv93Zw release-keys");
            property_set("ro.build.fingerprint", "Sony/D5306/D5306:4.4.3/19.1.1.A.0.165/Wv93Zw:user/release-keys");
            property_set("ro.telephony.default_network", "9");
            property_set("persist.radio.multisim.config", "");
            property_set("telephony.lteOnGsmDevice", "1");
        } else if (model == "5316") {
            /* D5316 (Xperia T2 Ultra LTE) */
            property_set("ro.product.model", "Xperia T2 Ultra");
            property_set("ro.product.device", "D5316");
            property_set("ro.build.product", "D5316");
            property_set("ro.build.description", "D5316-user 4.4.3 19.1.1.A.0.165 Wv93Zw release-keys");
            property_set("ro.build.fingerprint", "Sony/D5316/D5316:4.4.3/19.1.1.A.0.165/Wv93Zw:user/release-keys");
            property_set("ro.telephony.default_network", "9");
            property_set("persist.radio.multisim.config", "");
            property_set("telephony.lteOnGsmDevice", "1");
        } else if (model == "5322") {
            /* D5322 (Xperia T2 Ultra Dual) */
            property_set("ro.product.model", "Xperia T2 Ultra Dual");
            property_set("ro.product.device", "D5322");
            property_set("ro.build.product", "D5322");
            property_set("ro.build.description", "D5322-user 4.4.3 19.1.1.A.0.165 Wv93Zw release-keys");
            property_set("ro.build.fingerprint", "Sony/D5322/D5322:4.4.3/19.1.1.A.0.165/Wv93Zw:user/release-keys");
            property_set("ro.telephony.default_network", "9");
            property_set("ro.telephony.ril.config", "simactivation");
            property_set("persist.radio.multisim.config", "dsds");
            property_set("persist.radio.dont_use_dsd", "true");
            property_set("persist.radio.plmn_name_cmp", "1");
         } else {
            /* Recovery */
            property_set("ro.product.model", "Xperia T2 Ultra");
            property_set("ro.product.device", "tianchi");
            property_set("ro.build.product", "tianchi");
        }
    } else if (hardware == "seagull") {
        if (model == "5102") {
            /* D5102 (Xperia T3 3G) */
            property_set("ro.product.model", "Xperia T3 3G");
            property_set("ro.product.device", "D5102");
            property_set("ro.build.product", "D5102");
            property_set("ro.build.description", "D5102-user 4.4.2 18.1.A.1.21 6vt_bw release-keys");
            property_set("ro.build.fingerprint", "Sony/D5102/D5102:4.4.2/18.1.A.1.21/6vt_bw:user/release-keys");
            property_set("ro.telephony.default_network", "0");
            property_set("persist.radio.multisim.config", "");
        } else if (model == "5103") {
            /* D5103 (Xperia T3 LTE) */
            property_set("ro.product.model", "Xperia T3");
            property_set("ro.product.device", "D5103");
            property_set("ro.build.product", "D5103");
            property_set("ro.build.description", "D5103-user 4.4.2 18.1.A.1.21 6vt_bw release-keys");
            property_set("ro.build.fingerprint", "Sony/D5103/D5103:4.4.2/18.1.A.1.21/6vt_bw:user/release-keys");
            property_set("ro.telephony.default_network", "9");
            property_set("persist.radio.multisim.config", "");
            property_set("telephony.lteOnGsmDevice", "1");
        } else if (model == "5106") {
            /* D5106 (Xperia T3 LTE) */
            property_set("ro.product.model", "Xperia T3");
            property_set("ro.product.device", "D5106");
            property_set("ro.build.product", "D5106");
            property_set("ro.build.description", "D5106-user 4.4.2 18.1.A.1.21 6vt_bw release-keys");
            property_set("ro.build.fingerprint", "Sony/D5106/D5106:4.4.2/18.1.A.1.21/6vt_bw:user/release-keys");
            property_set("ro.telephony.default_network", "9");
            property_set("persist.radio.multisim.config", "");
            property_set("telephony.lteOnGsmDevice", "1");
        } else {
            /* Recovery */
            property_set("ro.product.model", "Xperia T3");
            property_set("ro.product.device", "seagull");
            property_set("ro.build.product", "seagull");
        }
    }    

    device = property_get("ro.product.device");
    ERROR("Found model %s setting build properties for %s device\n", model.c_str(), device.c_str());
}
