// Fill out your copyright notice in the Description page of Project Settings.

#include "DirectoryCall.h"
#include "Misc/Paths.h"
#include "HAL/PlatformFilemanager.h"

// 비디오 파일을 불러오는 경로를 반환하는 함수
FString UDirectoryCall::GetSavedVideoPath()
{
    FString VideoDir = FPaths::Combine(FPaths::ProjectSavedDir(), TEXT("Video/File1.mp4"));
    IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
    if (!PlatformFile.DirectoryExists(*VideoDir))
    {
        PlatformFile.CreateDirectory(*VideoDir);
    }
    return VideoDir;
}

// 오디오 파일을 불러오는 경로를 반환하는 함수
FString UDirectoryCall::GetSavedAudioPath()
{
    FString AudioDir = FPaths::Combine(FPaths::ProjectSavedDir(), TEXT("TTSUrls"));
    IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
    if (!PlatformFile.DirectoryExists(*AudioDir))
    {
        PlatformFile.CreateDirectory(*AudioDir);
    }
    return AudioDir;
}

// 오디오 파일을 불러오는 경로를 반환하는 함수
FString UDirectoryCall::GetSavedMergedAudioPath()
{
    FString AudioDir = FPaths::Combine(FPaths::ProjectSavedDir(), TEXT("Audio"));
    IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
    if (!PlatformFile.DirectoryExists(*AudioDir))
    {
        PlatformFile.CreateDirectory(*AudioDir);
    }
    return AudioDir;
}

// 최종 파일을 저장할 디렉토리 경로를 반환하는 함수
FString UDirectoryCall::GetSavedFinalDirectory()
{
    FString FinalDir = FPaths::Combine(FPaths::ProjectSavedDir(), TEXT("Output"));
    IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
    if (!PlatformFile.DirectoryExists(*FinalDir))
    {
        PlatformFile.CreateDirectory(*FinalDir);
    }
    return FinalDir;
}

// 최종 파일의 전체 경로를 반환하는 함수
FString UDirectoryCall::GetSavedFinalPath()
{
    FString FinalDirectory = GetSavedFinalDirectory();
    FString FinalFilePath = FPaths::Combine(FinalDirectory, TEXT("Drama.mp4"));
    return FinalFilePath;
}
