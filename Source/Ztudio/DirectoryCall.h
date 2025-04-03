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

    // ���� ���� ��θ� ��ȯ�ϴ� �Լ�
    UFUNCTION(BlueprintCallable, Category = "File Utilities")
        static FString GetSavedVideoPath();

    // TTS ����� ���� ��θ� ��ȯ�ϴ� �Լ�
    UFUNCTION(BlueprintCallable, Category = "File Utilities")
        static FString GetSavedAudioPath();

    // ��ģ ����� ���� ��θ� ��ȯ�ϴ� �Լ�
    UFUNCTION(BlueprintCallable, Category = "File Utilities")
        static FString GetSavedMergedAudioPath();

    // ���� ������ ������ ���丮 ��θ� ��ȯ�ϴ� �Լ�
    UFUNCTION(BlueprintCallable, Category = "File Utilities")
        static FString GetSavedFinalDirectory();

    // �������� ���� ��θ� ��ȯ�ϴ� �Լ�
    UFUNCTION(BlueprintCallable, Category = "File Utilities")
        static FString GetSavedFinalPath();

};
