// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DirectoryCall.generated.h"

/**
 *
 */
UCLASS(Blueprintable)
class FRAMECAPTUREDEMO_API UDirectoryCall : public UObject
{
    GENERATED_BODY()

public:

    // 비디오 파일 경로를 반환하는 함수
    UFUNCTION(BlueprintCallable, Category = "File Utilities")
        static FString GetSavedVideoPath();

    // TTS 오디오 파일 경로를 반환하는 함수
    UFUNCTION(BlueprintCallable, Category = "File Utilities")
        static FString GetSavedAudioPath();

    // 합친 오디오 파일 경로를 반환하는 함수
    UFUNCTION(BlueprintCallable, Category = "File Utilities")
        static FString GetSavedMergedAudioPath();

    // 최종 파일을 저장할 디렉토리 경로를 반환하는 함수
    UFUNCTION(BlueprintCallable, Category = "File Utilities")
        static FString GetSavedFinalDirectory();

    // 최종영상 파일 경로를 반환하는 함수
    UFUNCTION(BlueprintCallable, Category = "File Utilities")
        static FString GetSavedFinalPath();

};
