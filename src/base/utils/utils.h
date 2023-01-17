#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

#ifndef _UTILS_H_
#define _UTILS_H_

#include <QString>
#include <QCryptographicHash>
#include <QFile>
#include <QRegularExpression>
#include <QDebug>
#include <QUrl>
#include <QHostAddress>
#include <QPushButton>
#include <base/LibCfg.h>

DLL_DECL_SPEC QString Utils_Uint8ToHexQStr(uint8_t in);
DLL_DECL_SPEC QString Utils_Uint8ArrToHexQStr(uint8_t *arr, ssize_t len);
DLL_DECL_SPEC QString Utils_QByteArrayToHexQStr(const QByteArray& bytes_arr);
DLL_DECL_SPEC QByteArray Utils_RawHexStrToQByteArr(QString in_hexstr);
DLL_DECL_SPEC bool Utils_RawHexStrToArr(QString in_hexstr, uint8_t *out_arr, ssize_t *out_len, ssize_t max_len);
DLL_DECL_SPEC bool Utils_Sha512(uint8_t *in_data, ssize_t in_len, uint8_t outData[64]);

DLL_DECL_SPEC QString Utils_BytesToPrintableAsciiString(const QByteArray *in_arr);
DLL_DECL_SPEC QString Utils_BytesToAlphanumericString(const QByteArray *in_arr);
DLL_DECL_SPEC QString Utils_BytesToBinaryString(const QByteArray *in_arr);
DLL_DECL_SPEC QString Utils_BytesToDECString(const QByteArray *in_arr);

DLL_DECL_SPEC QString ParseCertOrCsrFromFileToHexStr(const QString& fileName);

DLL_DECL_SPEC QStringList Utils_ExtractAllUrls(const QString& inputText);
DLL_DECL_SPEC QStringList Utils_ExtractAllHosts(const QString &input);

DLL_DECL_SPEC bool Utils_IsValidIPv4(const QString &input);
DLL_DECL_SPEC bool Utils_IsValidIPv6(const QString &input);

DLL_DECL_SPEC void Utils_NumericListSort(QStringList *list);
DLL_DECL_SPEC bool Utils_FileExists(const QString& fileName);
DLL_DECL_SPEC QStringList Utils_ParseCsvLine(const QString &string);
DLL_DECL_SPEC QString Util_EncodeForCSV(const QString &string);
DLL_DECL_SPEC QString Utils_FloatWithDigitsPrecision(float number, int precision = 2);

DLL_DECL_SPEC void Utils_PushButtonStartLoading(QPushButton *button);
DLL_DECL_SPEC void Utils_PushButtonEndLoading(QPushButton *button);
DLL_DECL_SPEC void Utils_Alert(const QString &title, const QString &message);
DLL_DECL_SPEC void Utils_MsgBox(const QString &title, const QString &message);
DLL_DECL_SPEC void Utils_RichTextBoxPopup(const QString &title, const QString &content);

// Data structures utils
DLL_DECL_SPEC void Utils_PrintNestedQMap(const QVariantMap &map, int level = 0);
DLL_DECL_SPEC void Utils_PrintNestedQMap_AsQStrings(const QVariantMap &map, int level = 0);

DLL_DECL_SPEC QByteArrayList SplitByteArray(const QByteArray &in, QByteArray delimiter);

DLL_DECL_SPEC void SleepMs(quint64 ms);

#endif // _UTILS_H_

#pragma clang diagnostic pop