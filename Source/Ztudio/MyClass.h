// MyClass.h

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyClass.generated.h"

UCLASS()
class FRAMECAPTUREDEMO_API UMyClass : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    // ����� ������ ��ġ�� �Լ�
    UFUNCTION(BlueprintCallable, Category = "Audio")
        static bool CombineMultipleAudioFiles(const TArray<FString>& AudioFilePaths, const FString& OutputFilePath);

    // ������ ����� ������ ��ġ�� �Լ�
    UFUNCTION(BlueprintCallable, Category = "AudioVideo")
        static bool CombineFinalFiles(const FString& VideoFilePath, const FString& AudioFilePath, const FString& OutputFilePath);

    UFUNCTION(BlueprintCallable, Category = "Audio")
        static TArray<FString> GetWAVFilesFromDirectory(const FString& DirectoryPath);

};