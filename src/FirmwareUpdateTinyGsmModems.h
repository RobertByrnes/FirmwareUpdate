
void defineModem(TinyGsmType tinyGsmType) {
    if 
    switch (tinyGsmType) {
        case 0:
            #ifndef TINY_GSM_MODEM_SIM800
            #define TINY_GSM_MODEM_SIM800
            #endif
        break;
        case 1:
            #define TINY_GSM_MODEM_SIM808
        break;
        case 2:
            #define TINY_GSM_MODEM_SIM900
        break;
        case 3:
            #define TINY_GSM_MODEM_SIM7000
        break;
        case 4:
            #define TINY_GSM_MODEM_SIM7000SSL
        break;
        case 5:
            #define TINY_GSM_MODEM_SIM7070
        break;
        case 6:
            #define TINY_GSM_MMODEM_SIM7080
        break;
        case 7:
            #define TINY_GSM_MODEM_SIM7090
        break;
        case 8:
            #define TINY_GSM_MODEM_SIM5320
        break;
        case 9:
            #define TINY_GSM_MODEM_SIM5360
        break;
        case 10:
            #define TINY_GSM_MODEM_SIM5300
        break;
        case 11:
            #define TINY_GSM_MODEM_SIM5300
        break;
        case 12:
            #define TINY_GSM_MODEM_SIM7100
        break;
        case 13:
            #define TINY_GSM_MODEM_SIM7600
        break;
        case 14:
            #define TINY_GSM_MODEM_SIM7800
        break;
        case 15:
            #define TINY_GSM_MODEM_SIM7500
        break;
        case 16:
            #define TINY_GSM_MODEM_UBLOX
        break;
        case 17:
            #define TINY_GSM_MODEM_SARAR4
        break;
        case 18:
            #define TINY_GSM_MODEM_M95
        break;
        case 19:
            #define TINY_GSM_MODEM_BG96
        break;
        case 20:
            #define TINY_GSM_MODEM_A6
        break;
        case 21:
            #define TINY_GSM_MODEM_A7
        break;
        case 22:
            #define TINY_GSM_MODEM_M590
        break;
        case 23:
            #define TINY_GSM_MODEM_MC60
        break;
        case 24:
            #define TINY_GSM_MODEM_MC60E
        break;
        case 25:
            #define TINY_GSM_MODEM_ESP8266
        break;
        case 26:
            #define TINY_GSM_MODEM_XBEE
        break;
        case 27:
            #define TINY_GSM_MODEM_SEQUANS_MONARCH
        break;
        default:
            throw "Must define a modem";
    }
}