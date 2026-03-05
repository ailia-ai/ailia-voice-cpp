/**
 * \~japanese
 * @file ailia_voice.h
 * @brief ailia Voice ライブラリ
 * @copyright AXELL CORPORATION, ailia Inc.
 * @date 2024/06/27
 */

#ifndef INCLUDED_AILIA_VOICE
#define INCLUDED_AILIA_VOICE

/* エラーコードと構造体 */

#include "ailia.h"
#include "ailia_audio.h"

/* 呼び出し規約 */

#if defined(_WIN64) || defined(_M_X64) || defined(__amd64__) || defined(__x86_64__) || defined(__APPLE__) || \
	defined(__ANDROID__) || defined(ANDROID) || defined(__linux__) || defined(NN_NINTENDO_SDK)
#define AILIA_API
#else
#define AILIA_API __stdcall
#endif

#ifdef __cplusplus
extern "C" {
#endif

/****************************************************************
 * 辞書定義
 **/

/**
 * \~japanese
 * @def AILIA_VOICE_DICTIONARY_TYPE_OPEN_JTALK
 * @brief OpenJtalk形式
 *
 * \~english
 * @def AILIA_VOICE_DICTIONARY_TYPE_OPEN_JTALK
 * @brief Format for OpenJTalk
 */
#define AILIA_VOICE_DICTIONARY_TYPE_OPEN_JTALK (0)

/**
 * \~japanese
 * @def AILIA_VOICE_DICTIONARY_TYPE_G2P_EN
 * @brief G2P_EN形式
 *
 * \~english
 * @def AILIA_VOICE_DICTIONARY_TYPE_G2P_EN
 * @brief Format for G2P_EN
 */
#define AILIA_VOICE_DICTIONARY_TYPE_G2P_EN (1)

/**
 * \~japanese
 * @def AILIA_VOICE_DICTIONARY_TYPE_G2P_CN
 * @brief G2P_CN形式
 *
 * \~english
 * @def AILIA_VOICE_DICTIONARY_TYPE_G2P_CN
 * @brief Format for G2P_CN
 */
#define AILIA_VOICE_DICTIONARY_TYPE_G2P_CN (2)

/**
 * \~japanese
 * @def AILIA_VOICE_DICTIONARY_TYPE_G2PW
 * @brief G2PW形式（中国語多音字対応）
 *
 * \~english
 * @def AILIA_VOICE_DICTIONARY_TYPE_G2PW
 * @brief Format for G2PW (Chinese polyphone disambiguation)
 */
#define AILIA_VOICE_DICTIONARY_TYPE_G2PW (3)

/****************************************************************
 * アルゴリズム定義
 **/

/**
 * \~japanese
 * @def AILIA_VOICE_MODEL_TYPE_TACOTRON2
 * @brief Tacoreon2形式
 *
 * \~english
 * @def AILIA_VOICE_MODEL_TYPE_TACOTRON2
 * @brief Format for Tacotron2
 */
#define AILIA_VOICE_MODEL_TYPE_TACOTRON2 (0)

/**
 * \~japanese
 * @def AILIA_VOICE_MODEL_TYPE_GPT_SOVITS
 * @brief GPT-SoVITS形式
 *
 * \~english
 * @def AILIA_VOICE_MODEL_TYPE_GPT_SOVITS
 * @brief Format for GPT-SoVITS
 */
#define AILIA_VOICE_MODEL_TYPE_GPT_SOVITS (1)

/**
 * \~japanese
 * @def AILIA_VOICE_MODEL_TYPE_GPT_SOVITS_V2
 * @brief GPT-SoVITS V2形式
 *
 * \~english
 * @def AILIA_VOICE_MODEL_TYPE_GPT_SOVITS_V2
 * @brief Format for GPT-SoVITS V2
 */
#define AILIA_VOICE_MODEL_TYPE_GPT_SOVITS_V2 (2)

/**
 * \~japanese
 * @def AILIA_VOICE_MODEL_TYPE_GPT_SOVITS_V3
 * @brief GPT-SoVITS v3形式
 *
 * \~english
 * @def AILIA_VOICE_MODEL_TYPE_GPT_SOVITS_V3
 * @brief Format for GPT-SoVITS v3
 */
#define AILIA_VOICE_MODEL_TYPE_GPT_SOVITS_V3 (3)

/**
 * \~japanese
 * @def AILIA_VOICE_MODEL_TYPE_GPT_SOVITS_V2_PRO
 * @brief GPT-SoVITS v2-pro形式
 *
 * \~english
 * @def AILIA_VOICE_MODEL_TYPE_GPT_SOVITS_V2_PRO
 * @brief Format for GPT-SoVITS v2-pro
 */
#define AILIA_VOICE_MODEL_TYPE_GPT_SOVITS_V2_PRO (4)

/**
 * \~japanese
 * @def AILIA_VOICE_CLEANER_TYPE_BASIC
 * @brief BasicCleaner
 *
 * \~english
 * @def AILIA_VOICE_CLEANER_TYPE_BASIC
 * @brief BasicCleaner
 */
#define AILIA_VOICE_CLEANER_TYPE_BASIC (0)

/**
 * \~japanese
 * @def AILIA_VOICE_CLEANER_TYPE_ENGLISH
 * @brief EnglishCleaner
 *
 * \~english
 * @def AILIA_VOICE_CLEANER_TYPE_ENGLISH
 * @brief EnglishCleaner
 */
#define AILIA_VOICE_CLEANER_TYPE_ENGLISH (1)

/****************************************************************
 * フラグ定義
 **/

/**
 * \~japanese
 * @def AILIA_VOICE_FLAG_NONE
 * @brief フラグを設定しません
 *
 * \~english
 * @def AILIA_VOICE_FLAG_NONE
 * @brief Default flag
 */
#define AILIA_VOICE_FLAG_NONE (0)

/****************************************************************
 * G2Pの処理タイプ
 **/

/**
 * \~japanese
 * @def AILIA_VOICE_G2P_TYPE_GPT_SOVITS_EN
 * @brief GPT_SOVITSの英語向けの処理
 *
 * \~english
 * @def AILIA_VOICE_G2P_TYPE_GPT_SOVITS_EN
 * @brief GPT SOVITS English
 */
#define AILIA_VOICE_G2P_TYPE_GPT_SOVITS_EN (1)

/**
 * \~japanese
 * @def AILIA_VOICE_G2P_TYPE_GPT_SOVITS_JA
 * @brief GPT_SOVITSの日本語向けの処理
 *
 * \~english
 * @def AILIA_VOICE_G2P_TYPE_GPT_SOVITS_JA
 * @brief GPT SOVITS Japanese
 */
#define AILIA_VOICE_G2P_TYPE_GPT_SOVITS_JA (2)

/**
 * \~japanese
 * @def AILIA_VOICE_G2P_TYPE_GPT_SOVITS_ZH
 * @brief GPT_SOVITSの中国語向けの処理
 *
 * \~english
 * @def AILIA_VOICE_G2P_TYPE_GPT_SOVITS_ZH
 * @brief GPT SOVITS Chinese
 */
#define AILIA_VOICE_G2P_TYPE_GPT_SOVITS_ZH (3)

#define AILIA_VOICE_TEXT_POST_PROCESS_APPEND_PUNCTUATION (2) // 互換性用

/****************************************************************
 * APIコールバック定義
 **/

//接続が必要なAPI

#if defined(_WIN32) && !defined(_WIN64)
	#define AILIA_VOICE_USER_API __stdcall
#else
	#define AILIA_VOICE_USER_API
#endif

// ailia.audio API
typedef int(AILIA_VOICE_USER_API* AILIA_VOICE_USER_API_AILIA_AUDIO_RESAMPLE)(void*, const void*, int, int, int, int);
typedef int(AILIA_VOICE_USER_API* AILIA_VOICE_USER_API_AILIA_AUDIO_GET_RESAMPLE_LEN)(int*, int, int, int);
typedef int(AILIA_VOICE_USER_API* AILIA_VOICE_USER_API_AILIA_AUDIO_GET_FRAME_LEN)(int*, int, int, int, int);
typedef int(AILIA_VOICE_USER_API* AILIA_VOICE_USER_API_AILIA_AUDIO_GET_SPECTROGRAM)(void*, const void*, int, int, int, int, int, int, int, float, int);
typedef int(AILIA_VOICE_USER_API* AILIA_VOICE_USER_API_AILIA_AUDIO_GET_MEL_SPECTROGRAM)(void*, const void*, int, int, int, int, int, int, int, int, float, int, float, float, int, int, int);

// ailia API
typedef int(AILIA_VOICE_USER_API* AILIA_VOICE_USER_API_AILIA_CREATE)(struct AILIANetwork **, int, int);
typedef int(AILIA_VOICE_USER_API* AILIA_VOICE_USER_API_AILIA_OPEN_WEIGHT_FILE_A)(struct AILIANetwork *, const char *);
typedef int(AILIA_VOICE_USER_API* AILIA_VOICE_USER_API_AILIA_OPEN_WEIGHT_FILE_W)(struct AILIANetwork *, const wchar_t *);
typedef int(AILIA_VOICE_USER_API* AILIA_VOICE_USER_API_AILIA_OPEN_WEIGHT_MEM)(struct AILIANetwork *, const void *, unsigned int);
typedef int(AILIA_VOICE_USER_API* AILIA_VOICE_USER_API_AILIA_SET_MEMORY_MODE)(struct AILIANetwork*, unsigned int);
typedef void(AILIA_VOICE_USER_API* AILIA_VOICE_USER_API_AILIA_DESTROY)(struct AILIANetwork *);
typedef int(AILIA_VOICE_USER_API* AILIA_VOICE_USER_API_AILIA_UPDATE)(struct AILIANetwork *);
typedef int(AILIA_VOICE_USER_API* AILIA_VOICE_USER_API_AILIA_GET_BLOB_INDEX_BY_INPUT_INDEX)(struct AILIANetwork *, unsigned int *, unsigned int);
typedef int(AILIA_VOICE_USER_API* AILIA_VOICE_USER_API_AILIA_GET_BLOB_INDEX_BY_OUTPUT_INDEX)(struct AILIANetwork *, unsigned int *, unsigned int);
typedef int(AILIA_VOICE_USER_API* AILIA_VOICE_USER_API_AILIA_GET_BLOB_DATA)(struct AILIANetwork *, void*, unsigned int, unsigned int);
typedef int(AILIA_VOICE_USER_API* AILIA_VOICE_USER_API_AILIA_SET_INPUT_BLOB_DATA)(struct AILIANetwork *, const void*, unsigned int, unsigned int);
typedef int(AILIA_VOICE_USER_API* AILIA_VOICE_USER_API_AILIA_SET_INPUT_BLOB_SHAPE)(struct AILIANetwork *, const AILIAShape*, unsigned int, unsigned int);
typedef int(AILIA_VOICE_USER_API* AILIA_VOICE_USER_API_AILIA_GET_BLOB_SHAPE)(struct AILIANetwork *, AILIAShape*, unsigned int, unsigned int);
typedef int(AILIA_VOICE_USER_API* AILIA_VOICE_USER_API_AILIA_GET_INPUT_BLOB_COUNT)(struct AILIANetwork *, unsigned int *);
typedef int(AILIA_VOICE_USER_API* AILIA_VOICE_USER_API_AILIA_GET_OUTPUT_BLOB_COUNT)(struct AILIANetwork *, unsigned int *);
typedef const char*(AILIA_VOICE_USER_API* AILIA_VOICE_USER_API_AILIA_GET_ERROR_DETAIL)(struct AILIANetwork *);
typedef int(AILIA_VOICE_USER_API* AILIA_VOICE_USER_API_AILIA_COPY_BLOB_DATA)(struct AILIANetwork* dst_net, unsigned int dst_blob_idx, struct AILIANetwork* src_net, unsigned int src_blob_idx);

/**
* \~japanese
* @def AILIA_VOICE_API_CALLBACK_VERSION
* @brief 構造体バージョン
*
* \~english
* @def AILIA_VOICE_API_CALLBACK_VERSION
* @brief Struct version
*/
#define AILIA_VOICE_API_CALLBACK_VERSION (3)

/* APIコールバック関数構造体 */
typedef struct _AILIAVoiceApiCallback {
	AILIA_VOICE_USER_API_AILIA_AUDIO_RESAMPLE ailiaAudioResample;
	AILIA_VOICE_USER_API_AILIA_AUDIO_GET_RESAMPLE_LEN ailiaAudioGetResampleLen;
	AILIA_VOICE_USER_API_AILIA_AUDIO_GET_FRAME_LEN ailiaAudioGetFrameLen;
	AILIA_VOICE_USER_API_AILIA_AUDIO_GET_SPECTROGRAM ailiaAudioGetSpectrogram;
	AILIA_VOICE_USER_API_AILIA_AUDIO_GET_MEL_SPECTROGRAM ailiaAudioGetMelSpectrogram;
	AILIA_VOICE_USER_API_AILIA_CREATE ailiaCreate;
	AILIA_VOICE_USER_API_AILIA_OPEN_WEIGHT_FILE_A ailiaOpenWeightFileA;
	AILIA_VOICE_USER_API_AILIA_OPEN_WEIGHT_FILE_W ailiaOpenWeightFileW;
	AILIA_VOICE_USER_API_AILIA_OPEN_WEIGHT_MEM ailiaOpenWeightMem;
	AILIA_VOICE_USER_API_AILIA_SET_MEMORY_MODE ailiaSetMemoryMode;
	AILIA_VOICE_USER_API_AILIA_DESTROY ailiaDestroy;
	AILIA_VOICE_USER_API_AILIA_UPDATE ailiaUpdate;
	AILIA_VOICE_USER_API_AILIA_GET_BLOB_INDEX_BY_INPUT_INDEX ailiaGetBlobIndexByInputIndex;
	AILIA_VOICE_USER_API_AILIA_GET_BLOB_INDEX_BY_OUTPUT_INDEX ailiaGetBlobIndexByOutputIndex;
	AILIA_VOICE_USER_API_AILIA_GET_BLOB_DATA ailiaGetBlobData;
	AILIA_VOICE_USER_API_AILIA_SET_INPUT_BLOB_DATA ailiaSetInputBlobData;
	AILIA_VOICE_USER_API_AILIA_SET_INPUT_BLOB_SHAPE ailiaSetInputBlobShape;
	AILIA_VOICE_USER_API_AILIA_GET_BLOB_SHAPE ailiaGetBlobShape;
	AILIA_VOICE_USER_API_AILIA_GET_INPUT_BLOB_COUNT ailiaGetInputBlobCount;
	AILIA_VOICE_USER_API_AILIA_GET_OUTPUT_BLOB_COUNT ailiaGetOutputBlobCount;
	AILIA_VOICE_USER_API_AILIA_GET_ERROR_DETAIL ailiaGetErrorDetail;
	AILIA_VOICE_USER_API_AILIA_COPY_BLOB_DATA ailiaCopyBlobData;
} AILIAVoiceApiCallback;

/****************************************************************
 * ボイスオブジェクトのインスタンス
 **/

struct AILIAVoice;

/****************************************************************
 * Voice API
 **/

/**
 * \~japanese
 * @brief ボイスオブジェクトを作成します。
 * @param net ボイスオブジェクトポインタへのポインタ
 * @param env_id 計算に利用する推論実行環境のID( ailiaGetEnvironment() で取得)  \ref AILIA_ENVIRONMENT_ID_AUTO にした場合は自動で選択する
 * @param num_thread スレッド数の上限(  \ref AILIA_MULTITHREAD_AUTO  にした場合は自動で設定)
 * @param memory_mode メモリモード(AILIA_MEMORY_MODE_*)
 * @param flag AILIA_VOICE_FLAG_*の論理和
 * @param api_callback ailiaのAPIへのコールバック
 * @param version AILIA_VOICE_API_CALLBACK_VERSION
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 * @details
 *   ボイスオブジェクトを作成します。
 *
 * \~english
 * @brief Creates a Voice instance.
 * @param net A pointer to the Voice instance pointer
 * @param env_id The ID of the inference backend used for computation (obtained by  ailiaGetEnvironment() ). It is selected automatically if  \ref AILIA_ENVIRONMENT_ID_AUTO  is specified.
 * @param num_thread The upper limit on the number of threads (It is set automatically if  \ref AILIA_MULTITHREAD_AUTO
 * @param memory_mode The memory mode (AILIA_MEMORY_MODE_*)
 * @param flag OR of AILIA_VOICE_FLAG_*
 * @param api_callback The callback for ailia API
 * @param version AILIA_VOICE_API_CALLBACK_VERSION
 * is specified.)
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 * @details
 *   Creates a Voice instance.
 */
int AILIA_API ailiaVoiceCreate(struct AILIAVoice** net, int env_id, int num_thread, int memory_mode, int flags, AILIAVoiceApiCallback callback, int version);

/**
 * \~japanese
 * @brief ユーザ辞書を指定します。(MBSC)
 * @param net ネットワークオブジェクトポインタ
 * @param dictionary_path ユーザ辞書ファイルのパス名(MBSC)
 * @param dictionary_type AILIA_VOICE_DICTIONARY_TYPE_*
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 * @details
 *   ailiaVoiceOpenDictionaryFileAの前に呼び出す必要があります。
 *
 * \~english
 * @brief Set user dictionary into a network instance.
 * @param net A network instance pointer
 * @param dictionary_path The path name to the user dictionary file (MBSC)
 * @param dictionary_type AILIA_VOICE_DICTIONARY_TYPE_*
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 * @details
 *   You need to call before ailiaVoiceOpenDictionaryFileA.
 */
int AILIA_API ailiaVoiceSetUserDictionaryFileA(struct AILIAVoice* net, const char* dictionary_path, int dictionary_type);

/**
 * \~japanese
 * @brief ユーザ辞書を指定します。(UTF16)
 * @param net ネットワークオブジェクトポインタ
 * @param dictionary_path ユーザ辞書ファイルのパス名(UTF16)
 * @param dictionary_type AILIA_VOICE_DICTIONARY_TYPE_*
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 * @details
 *   ailiaVoiceOpenDictionaryFileWの前に呼び出す必要があります。
 *
 * \~english
 * @brief Set user dictionary into a network instance.
 * @param net A network instance pointer
 * @param dictionary_path The path name to the user dictionary file (UTF16)
 * @param dictionary_type AILIA_VOICE_DICTIONARY_TYPE_*
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 * @details
 *   You need to call before ailiaVoiceOpenDictionaryFileW.
 */
int AILIA_API ailiaVoiceSetUserDictionaryFileW(struct AILIAVoice* net, const wchar_t* dictionary_path, int dictionary_type);

/**
 * \~japanese
 * @brief 辞書を指定します。(MBSC)
 * @param net ネットワークオブジェクトポインタ
 * @param dictionary_path 辞書フォルダのパス名(MBSC)
 * @param dictionary_type AILIA_VOICE_DICTIONARY_TYPE_*
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 * @details
 *   中国語を使用する場合、GPT-SoVITS V1では \ref AILIA_VOICE_DICTIONARY_TYPE_G2P_CN のみ必要です。
 *   GPT-SoVITS V2およびV3では \ref AILIA_VOICE_DICTIONARY_TYPE_G2P_CN と
 *   \ref AILIA_VOICE_DICTIONARY_TYPE_G2PW の両方が必要です。
 *   G2PWを使用する場合、先にG2P_CNを読み込んでください。
 *
 * \~english
 * @brief Set dictionary into a network instance.
 * @param net A network instance pointer
 * @param dictionary_path The path name to the dictionary folder (MBSC)
 * @param dictionary_type AILIA_VOICE_DICTIONARY_TYPE_*
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 * @details
 *   For Chinese, GPT-SoVITS V1 requires only \ref AILIA_VOICE_DICTIONARY_TYPE_G2P_CN .
 *   GPT-SoVITS V2 and V3 require both \ref AILIA_VOICE_DICTIONARY_TYPE_G2P_CN and
 *   \ref AILIA_VOICE_DICTIONARY_TYPE_G2PW .
 *   When using G2PW, load G2P_CN first.
 */
int AILIA_API ailiaVoiceOpenDictionaryFileA(struct AILIAVoice* net, const char* dictionary_path, int dictionary_type);

/**
 * \~japanese
 * @brief 辞書を指定します。(UTF16)
 * @param net ネットワークオブジェクトポインタ
 * @param dictionary_path 辞書フォルダのパス名(UTF16)
 * @param dictionary_type AILIA_VOICE_DICTIONARY_TYPE_*
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 * @details
 *   中国語を使用する場合、GPT-SoVITS V1では \ref AILIA_VOICE_DICTIONARY_TYPE_G2P_CN のみ必要です。
 *   GPT-SoVITS V2およびV3では \ref AILIA_VOICE_DICTIONARY_TYPE_G2P_CN と
 *   \ref AILIA_VOICE_DICTIONARY_TYPE_G2PW の両方が必要です。
 *   G2PWを使用する場合、先にG2P_CNを読み込んでください。
 *
 * \~english
 * @brief Set dictionary into a network instance.
 * @param net A network instance pointer
 * @param dictionary_path The path name to the dictionary folder (UTF16)
 * @param dictionary_type AILIA_VOICE_DICTIONARY_TYPE_*
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 * @details
 *   For Chinese, GPT-SoVITS V1 requires only \ref AILIA_VOICE_DICTIONARY_TYPE_G2P_CN .
 *   GPT-SoVITS V2 and V3 require both \ref AILIA_VOICE_DICTIONARY_TYPE_G2P_CN and
 *   \ref AILIA_VOICE_DICTIONARY_TYPE_G2PW .
 *   When using G2PW, load G2P_CN first.
 */
int AILIA_API ailiaVoiceOpenDictionaryFileW(struct AILIAVoice* net, const wchar_t* dictionary_path, int dictionary_type);

/**
 * \~japanese
 * @brief モデルを指定します。(MBSC)
 * @param net ネットワークオブジェクトポインタ
 * @param encoder_path onnxファイルのパス名(MBSC)
 * @param decoder1_path onnxファイルのパス名(MBSC)
 * @param decoder2_path onnxファイルのパス名(MBSC)
 * @param wave_path onnxファイルのパス名(MBSC)
 * @param ssl_path onnxファイルのパス名(MBSC)
 * @param model_type AILIA_VOICE_MODEL_TYPE_*
 * @param cleaner_type AILIA_VOICE_CLEANER_TYPE_*
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 *
 * \~english
 * @brief Set models into a network instance.
 * @param net A network instance pointer
 * @param encoder The path name to the onnx file (MBSC)
 * @param decoder1 The path name to the onnx file (MBSC)
 * @param decoder2 The path name to the onnx file (MBSC)
 * @param wave The path name to the onnx file (MBSC)
 * @param ssl The path name to the onnx file (MBSC)
 * @param model_type AILIA_VOICE_MODEL_TYPE_*
 * @param cleaner_type AILIA_VOICE_CLEANER_TYPE_*
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 */
int AILIA_API ailiaVoiceOpenModelFileA(struct AILIAVoice* net, const char* encoder, const char* decoder1, const char* decoder2, const char* wave, const char* ssl, int model_type, int cleaner_type);

/**
 * \~japanese
 * @brief モデルを指定します。(UTF16)
 * @param net ネットワークオブジェクトポインタ
 * @param encoder onnxファイルのパス名(UTF16)
 * @param decoder1 onnxファイルのパス名(UTF16)
 * @param decoder2 onnxファイルのパス名(UTF16)
 * @param wave onnxファイルのパス名(UTF16)
 * @param ssl onnxファイルのパス名(UTF16)
 * @param model_type AILIA_VOICE_MODEL_TYPE_*
 * @param cleaner_type AILIA_VOICE_CLEANER_TYPE_*
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 *
 * \~english
 * @brief Set models into a network instance.
 * @param net A network instance pointer
 * @param encoder The path name to the onnx file (UTF16)
 * @param decoder1 The path name to the onnx file (UTF16)
 * @param decoder2 The path name to the onnx file (UTF16)
 * @param wave The path name to the onnx file (UTF16)
 * @param ssl The path name to the onnx file (UTF16)
 * @param model_type AILIA_VOICE_MODEL_TYPE_*
 * @param cleaner_type AILIA_VOICE_CLEANER_TYPE_*
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 */
int AILIA_API ailiaVoiceOpenModelFileW(struct AILIAVoice* net, const wchar_t* encoder, const wchar_t* decoder1, const wchar_t* decoder2, const wchar_t* wave, const wchar_t* ssl, int model_type, int cleaner_type);

/**
 * \~japanese
 * @brief GPT-SoVITS V3向けのモデルを指定します。(MBSC)
 * @param net ネットワークオブジェクトポインタ
 * @param encoder_path onnxファイルのパス名 (t2s_encoder.onnx) (MBSC)
 * @param decoder1_path onnxファイルのパス名 (t2s_fsdec.onnx) (MBSC)
 * @param decoder2_path onnxファイルのパス名 (t2s_sdec.onnx) (MBSC)
 * @param ssl_path onnxファイルのパス名 (cnhubert.onnx) (MBSC)
 * @param vq_path onnxファイルのパス名 (vq_model.onnx) (MBSC)
 * @param cfm_path onnxファイルのパス名 (vq_cfm.onnx) (MBSC)
 * @param bigvgan_path onnxファイルのパス名 (bigvgan_model.onnx) (MBSC)
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 *
 * \~english
 * @brief Set GPT-SoVITS V3 models into a network instance.
 * @param net A network instance pointer
 * @param encoder The path name to the onnx file (t2s_encoder.onnx) (MBSC)
 * @param decoder1 The path name to the onnx file (t2s_fsdec.onnx) (MBSC)
 * @param decoder2 The path name to the onnx file (t2s_sdec.onnx) (MBSC)
 * @param ssl The path name to the onnx file (cnhubert.onnx) (MBSC)
 * @param vq The path name to the onnx file (vq_model.onnx) (MBSC)
 * @param cfm The path name to the onnx file (vq_cfm.onnx) (MBSC)
 * @param bigvgan The path name to the onnx file (bigvgan_model.onnx) (MBSC)
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 */
int AILIA_API ailiaVoiceOpenModelFileGPTSoVITSV3A(struct AILIAVoice* net, const char* encoder, const char* decoder1, const char* decoder2, const char* ssl, const char* vq, const char* cfm, const char* bigvgan);

/**
 * \~japanese
 * @brief GPT-SoVITS V3向けのモデルを指定します。(UTF16)
 * @param net ネットワークオブジェクトポインタ
 * @param encoder onnxファイルのパス名 (t2s_encoder.onnx) (UTF16)
 * @param decoder1 onnxファイルのパス名 (t2s_fsdec.onnx) (UTF16)
 * @param decoder2 onnxファイルのパス名 (t2s_sdec.onnx) (UTF16)
 * @param ssl onnxファイルのパス名 (cnhubert.onnx) (UTF16)
 * @param vq onnxファイルのパス名 (vq_model.onnx) (UTF16)
 * @param cfm onnxファイルのパス名 (vq_cfm.onnx) (UTF16)
 * @param bigvgan onnxファイルのパス名 (bigvgan_model.onnx) (UTF16)
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 *
 * \~english
 * @brief Set GPT-SoVITS V3 models into a network instance.
 * @param net A network instance pointer
 * @param encoder The path name to the onnx file (t2s_encoder.onnx) (UTF16)
 * @param decoder1 The path name to the onnx file (t2s_fsdec.onnx) (UTF16)
 * @param decoder2 The path name to the onnx file (t2s_sdec.onnx) (UTF16)
 * @param ssl The path name to the onnx file (cnhubert.onnx) (UTF16)
 * @param vq The path name to the onnx file (vq_model.onnx) (UTF16)
 * @param cfm The path name to the onnx file (vq_cfm.onnx) (UTF16)
 * @param bigvgan The path name to the onnx file (bigvgan_model.onnx) (UTF16)
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 */
int AILIA_API ailiaVoiceOpenModelFileGPTSoVITSV3W(struct AILIAVoice* net, const wchar_t* encoder, const wchar_t* decoder1, const wchar_t* decoder2, const wchar_t* ssl, const wchar_t* vq, const wchar_t* cfm, const wchar_t* bigvgan);

/**
 * \~japanese
 * @brief GPT-SoVITS V2-Pro向けのモデルを指定します。(MBSC)
 * @param net ネットワークオブジェクトポインタ
 * @param encoder onnxファイルのパス名 (t2s_encoder.onnx) (MBSC)
 * @param decoder1 onnxファイルのパス名 (t2s_fsdec.onnx) (MBSC)
 * @param decoder2 onnxファイルのパス名 (t2s_sdec.onnx) (MBSC)
 * @param ssl onnxファイルのパス名 (cnhubert.onnx) (MBSC)
 * @param vits onnxファイルのパス名 (vits.onnx) (MBSC)
 * @param sv onnxファイルのパス名 (sv.onnx) (MBSC)
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 *
 * \~english
 * @brief Set GPT-SoVITS V2-Pro models into a network instance.
 * @param net A network instance pointer
 * @param encoder The path name to the onnx file (t2s_encoder.onnx) (MBSC)
 * @param decoder1 The path name to the onnx file (t2s_fsdec.onnx) (MBSC)
 * @param decoder2 The path name to the onnx file (t2s_sdec.onnx) (MBSC)
 * @param ssl The path name to the onnx file (cnhubert.onnx) (MBSC)
 * @param vits The path name to the onnx file (vits.onnx) (MBSC)
 * @param sv The path name to the onnx file (sv.onnx) (MBSC)
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 */
int AILIA_API ailiaVoiceOpenModelFileGPTSoVITSV2ProA(struct AILIAVoice* net, const char* encoder, const char* decoder1, const char* decoder2, const char* ssl, const char* vits, const char* sv);

/**
 * \~japanese
 * @brief GPT-SoVITS V2-Pro向けのモデルを指定します。(UTF16)
 * @param net ネットワークオブジェクトポインタ
 * @param encoder onnxファイルのパス名 (t2s_encoder.onnx) (UTF16)
 * @param decoder1 onnxファイルのパス名 (t2s_fsdec.onnx) (UTF16)
 * @param decoder2 onnxファイルのパス名 (t2s_sdec.onnx) (UTF16)
 * @param ssl onnxファイルのパス名 (cnhubert.onnx) (UTF16)
 * @param vits onnxファイルのパス名 (vits.onnx) (UTF16)
 * @param sv onnxファイルのパス名 (sv.onnx) (UTF16)
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 *
 * \~english
 * @brief Set GPT-SoVITS V2-Pro models into a network instance.
 * @param net A network instance pointer
 * @param encoder The path name to the onnx file (t2s_encoder.onnx) (UTF16)
 * @param decoder1 The path name to the onnx file (t2s_fsdec.onnx) (UTF16)
 * @param decoder2 The path name to the onnx file (t2s_sdec.onnx) (UTF16)
 * @param ssl The path name to the onnx file (cnhubert.onnx) (UTF16)
 * @param vits The path name to the onnx file (vits.onnx) (UTF16)
 * @param sv The path name to the onnx file (sv.onnx) (UTF16)
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 */
int AILIA_API ailiaVoiceOpenModelFileGPTSoVITSV2ProW(struct AILIAVoice* net, const wchar_t* encoder, const wchar_t* decoder1, const wchar_t* decoder2, const wchar_t* ssl, const wchar_t* vits, const wchar_t* sv);

/**
 * \~japanese
 * @brief G2Pを行います。
 * @param net ボイスオブジェクトポインタ
 * @param text テキスト(UTF8)
 * @param g2p_type AILIA_VOICE_G2P_TYPE_*
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 * @details
 *   認識した結果はailiaVoiceGetFeatures APIで取得します。
 *
 * \~english
 * @brief Perform g2p
 * @param net A Voice instance pointer
 * @param text Text(UTF8)
 * @param g2p_type AILIA_VOICE_G2P_TYPE_*
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 * @details
 *   Get the result with ailiaVoiceGetFeatures API.
 */
int AILIA_API ailiaVoiceGraphemeToPhoneme(struct AILIAVoice* net, const char *utf8, int g2p_type);

/**
 * \~japanese
 * @brief ExtractFullContextを行います。
 * @param net ボイスオブジェクトポインタ
 * @param text テキスト(UTF8)
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 * @details
 *   認識した結果はailiaVoiceGetFeaturesAPIで取得します。
 *
 * \~english
 * @brief Perform ExtractFullContext
 * @param net A Voice instance pointer
 * @param text Text (UTF8)
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 * @details
 *   Get the result with ailiaVoiceGetFeatures API.
 */
int AILIA_API ailiaVoiceExtractFullContext(struct AILIAVoice* net, const char *utf8);

/**
 * \~japanese
 * @brief フィーチャーの長さを取得します。(NULL文字含む)
 * @param net   ボイスオブジェクトポインタ
 * @param len  フィーチャーの長さ
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 *
 * \~english
 * @brief Gets the size of features. (Include null)
 * @param net   A Voice instance pointer
 * @param len  The length of features
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 */
int AILIA_API ailiaVoiceGetFeatureLength(struct AILIAVoice* net, unsigned int* len);

/**
 * \~japanese
 * @brief フィーチャーを取得します。
 * @param net   ボイスオブジェクトポインタ
 * @param features  フィーチャー(UTF8)
 * @param len フィーチャーの長さ
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 * @details
 *   ailiaVoiceGraphemeToPhoneme() もしくは ailiaVoiceExtractFullContext() を一度も実行していない場合は \ref AILIA_STATUS_INVALID_STATE が返ります。
 *
 * \~english
 * @brief Gets the decoded features.
 * @param net   A Voice instance pointer
 * @param features  Features(UTF8)
 * @param len  The length of features
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 * @details
 *   If  ailiaVoiceGraphemeToPhoneme()  or ailiaVoiceExtractFullContext() is not run at all, the function returns  \ref AILIA_STATUS_INVALID_STATE .
 */
int AILIA_API ailiaVoiceGetFeatures(struct AILIAVoice* net, char* features, unsigned int len);

/**
 * \~japanese
 * @brief 0ショット音声合成のリファレンスとなる波形とテキストを設定します。
 * @param net   ボイスオブジェクトポインタ
 * @param buf  PCM波形 (0 - 1で正規化)
 * @param buf_size バッファサイズ（byte単位）
 * @param channels チャンネル数
 * @param sampling_rate サンプリングレート
 * @param features フィーチャー(UTF8)
 * 
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 *
 * \~english
 * @brief Set the waveform and text as references for zero-shot voice synthesis.
 * @param net   A Voice instance pointer
 * @param buf   PCM Wave (Normalized by 0 - 1)
 * @param buf_size buffer size (byte unit)
 * @param channels num channels
 * @param sampling_rate sampling rate
 * @param features Feature (UTF8)
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 */
int AILIA_API ailiaVoiceSetReference(struct AILIAVoice* net, float* buf, unsigned int buf_size, unsigned int channels, unsigned int sampling_rate, const char *features);

/**
 * \~japanese
 * @brief GPT-SoVITS v3のCFMサンプリングステップ数を設定します。
 * @param net ボイスオブジェクトポインタ
 * @param steps CFMのEuler ODEステップ数(デフォルト4)
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 *
 * \~english
 * @brief Set the number of CFM sampling steps for GPT-SoVITS v3.
 * @param net A Voice instance pointer
 * @param steps Number of Euler ODE steps for CFM (default 4)
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 */
int AILIA_API ailiaVoiceSetSampleSteps(struct AILIAVoice* net, int steps);

/**
 * \~japanese
 * @brief 音声合成の速度を設定します。
 * @param net ボイスオブジェクトポインタ
 * @param speed 速度(デフォルト1.0、0より大きい値)
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 * @details
 *   GPT-SoVITS V2およびV3で使用できます。V1では無効です。
 *
 * \~english
 * @brief Set the speech speed for synthesis.
 * @param net A Voice instance pointer
 * @param speed Speed value (default 1.0, must be greater than 0)
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 * @details
 *   Supported by GPT-SoVITS V2 and V3. Not effective for V1.
 */
int AILIA_API ailiaVoiceSetSpeed(struct AILIAVoice* net, float speed);

/**
 * \~japanese
 * @brief G2Pで使用するモデルタイプを設定します。
 * @param net ボイスオブジェクトポインタ
 * @param model_type モデルタイプ（AILIA_VOICE_MODEL_TYPE_GPT_SOVITS, AILIA_VOICE_MODEL_TYPE_GPT_SOVITS_V2, AILIA_VOICE_MODEL_TYPE_GPT_SOVITS_V3, AILIA_VOICE_MODEL_TYPE_GPT_SOVITS_V2_PRO）
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 * @details
 *   G2Pを単独で使用する際に、モデルファイルを与えずにモデルタイプを設定することに使用します。
 *   ailiaVoiceOpenModelFileAまたはailiaVoiceOpenModelFileGPTSoVITSV3Aを呼び出した場合は自動的に設定されるため、本APIの呼び出しは不要です。
 *
 * \~english
 * @brief Set the model type used for G2P processing.
 * @param net A Voice instance pointer
 * @param model_type Model type (AILIA_VOICE_MODEL_TYPE_GPT_SOVITS, AILIA_VOICE_MODEL_TYPE_GPT_SOVITS_V2, AILIA_VOICE_MODEL_TYPE_GPT_SOVITS_V3, AILIA_VOICE_MODEL_TYPE_GPT_SOVITS_V2_PRO)
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 * @details
 *   Used to set the model type when using G2P standalone without opening model files.
 *   If ailiaVoiceOpenModelFileA or ailiaVoiceOpenModelFileGPTSoVITSV3A is called, the model type is set automatically, so calling this API is not required.
 */
int AILIA_API ailiaVoiceSetModelType(struct AILIAVoice* net, int model_type);

/**
 * \~japanese
 * @brief 推論を行います。
 * @param net ボイスオブジェクトポインタ
 * @param text テキスト(UTF8)
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 * @details
 *   音声合成した結果はailiaVoiceGetWave APIで取得します。
 *
 * \~english
 * @brief Perform inference
 * @param net A Voice instance pointer
 * @param text Text(UTF8)
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 * @details
 *   Get the result with ailiaVoiceGetWave API.
 */
int AILIA_API ailiaVoiceInference(struct AILIAVoice* net, const char *utf8);

/**
 * \~japanese
 * @brief 波形の情報を取得します。
 * @param net   ボイスオブジェクトポインタ
 * @param samples  サンプル数（チャンネル単位）
 * @param channels  チャンネル数
 * @param sampling_rate  サンプリングレート
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 *
 * \~english
 * @brief Gets the information of wave.
 * @param net   A Voice instance pointer
 * @param samples  Number of samples (per channel)
 * @param channels  Number of channels
 * @param sampling_rate  Sampling rate
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 */
int AILIA_API ailiaVoiceGetWaveInfo(struct AILIAVoice* net, unsigned int* samples, unsigned int* channels, unsigned int* sampling_rate);

/**
 * \~japanese
 * @brief 波形を取得します。
 * @param net   ボイスオブジェクトポインタ
 * @param buf  PCM波形 (0 - 1で正規化)
 * @param buf_size バッファサイズ（byte単位）
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 * @details
 *   ailiaVoiceInference() を一度も実行していない場合は \ref AILIA_STATUS_INVALID_STATE が返ります。
 *
 * \~english
 * @brief Gets the decoded features.
 * @param net   A Voice instance pointer
 * @param buf   PCM Wave (Normalized by 0 - 1)
 * @param buf_size  Buffer size (Byte unit)
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 * @details
 *   If  ailiaVoiceInference() is not run at all, the function returns  \ref AILIA_STATUS_INVALID_STATE .
 */
int AILIA_API ailiaVoiceGetWave(struct AILIAVoice* net, float* buf, unsigned int buf_size);

/**
 * \~japanese
 * @brief ボイスオブジェクトを破棄します。
 * @param net ボイスオブジェクトポインタ
 *
 * \~english
 * @brief It destroys the Voice instance.
 * @param net A Voice instance pointer
 */
void AILIA_API ailiaVoiceDestroy(struct AILIAVoice* net);

/**
 * \~japanese
 * @brief エラーの詳細を返します
 * @param net   ネットワークオブジェクトポインタ
 * @return
 *   エラー詳細
 * @details
 *   返値は解放する必要はありません。
 *   文字列の有効期間は次にailiaVoiceのAPIを呼ぶまでです。
 *
 * \~english
 * @brief Returns the details of errors.
 * @param net   The network instance pointer
 * @return
 *   Error details
 * @details
 *   The return value does not have to be released.
 *   The string is valid until the next ailiaVoice API function is called.
 */
const char* AILIA_API ailiaVoiceGetErrorDetail(struct AILIAVoice* net);

#ifdef UNICODE
#define ailiaVoiceSetUserDictionaryFile ailiaVoiceSetUserDictionaryFileW
#define ailiaVoiceOpenDictionaryFile ailiaVoiceOpenDictionaryFileW
#define ailiaVoiceOpenModelFile ailiaVoiceOpenModelFileW
#define ailiaVoiceOpenModelFileGPTSoVITSV3 ailiaVoiceOpenModelFileGPTSoVITSV3W
#define ailiaVoiceOpenModelFileGPTSoVITSV2Pro ailiaVoiceOpenModelFileGPTSoVITSV2ProW
#else
#define ailiaVoiceSetUserDictionaryFile ailiaVoiceSetUserDictionaryFileA
#define ailiaVoiceOpenDictionaryFile ailiaVoiceOpenDictionaryFileW
#define ailiaVoiceOpenModelFile ailiaVoiceOpenModelFileW
#define ailiaVoiceOpenModelFileGPTSoVITSV3 ailiaVoiceOpenModelFileGPTSoVITSV3A
#define ailiaVoiceOpenModelFileGPTSoVITSV2Pro ailiaVoiceOpenModelFileGPTSoVITSV2ProA
#endif

#ifdef __cplusplus
}
#endif
#endif /* !defined(INCLUDED_AILIA_Voice) */
