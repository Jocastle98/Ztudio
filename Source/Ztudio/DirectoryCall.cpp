// Fill out your copyright notice in the Description page of Project Settings.

#include "DirectoryCall.h"
#include "Misc/Paths.h"
#include "HAL/PlatformFilemanager.h"

// ���� ������ �ҷ����� ��θ� ��ȯ�ϴ� �Լ�
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

// ����� ������ �ҷ����� ��θ� ��ȯ�ϴ� �Լ�
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

// ����� ������ �ҷ����� ��θ� ��ȯ�ϴ� �Լ�
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

// ���� ������ ������ ���丮 ��θ� ��ȯ�ϴ� �Լ�
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

// ���� ������ ��ü ��θ� ��ȯ�ϴ� �Լ�
FString UDirectoryCall::GetSavedFinalPath()
{
    FString FinalDirectory = GetSavedFinalDirectory();
    FString FinalFilePath = FPaths::Combine(FinalDirectory, TEXT("Drama.mp4"));
    return FinalFilePath;
}
