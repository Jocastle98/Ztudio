#include "MyClass.h"
#include "Misc/Paths.h"
#include "HAL/PlatformFilemanager.h"
#include "Runtime/Core/Public/Misc/Paths.h"
#include "Runtime/Core/Public/HAL/PlatformProcess.h"

bool UMyClass::CombineMultipleAudioFiles(const TArray<FString>& AudioFilePaths, const FString& OutputFilePath)
{
    // FFmpeg ���� ������ ��θ� �ùٸ��� �����մϴ�.
    FString FFmpegExecutable = FPaths::Combine(FPaths::ProjectDir(), TEXT("Source/ThirdParty/ffmpeg.exe"));

    // �Է� ������ ���� ��� �μ��� �����մϴ�.
    FString InputArgs;
    for (int32 Index = 0; Index < AudioFilePaths.Num(); ++Index)
    {
        InputArgs += FString::Printf(TEXT("-i \"%s\" "), *AudioFilePaths[Index]);
    }

    // filter_complex �μ��� �����մϴ�.
    FString FilterComplex;
    for (int32 Index = 0; Index < AudioFilePaths.Num(); ++Index)
    {
        FilterComplex += FString::Printf(TEXT("[%d:0]"), Index);
    }
    FilterComplex += FString::Printf(TEXT("concat=n=%d:v=0:a=1[out]"), AudioFilePaths.Num());

    // ��� �� �μ��� ������ �����մϴ�.
// `-y` �÷��׸� CommandArgs ���� �κп� �߰��մϴ�.
    FString CommandArgs = FString::Printf(TEXT("-y %s -filter_complex \"%s\" -map \"[out]\" \"%s\""),
        *InputArgs,
        *FilterComplex,
        *OutputFilePath);

    // ���� ExecProcess�� ���� ���� ��ο� ��� �μ��� ȣ���մϴ�.
    int32 ReturnCode = 0;
    FString StdOut;
    FString StdErr;
    FPlatformProcess::ExecProcess(*FFmpegExecutable, *CommandArgs, &ReturnCode, &StdOut, &StdErr);

    // ���μ��� ���� ����� Ȯ���մϴ�.
    if (ReturnCode == 0)
    {
        // ���������� ����ƴٴ� ���� �ǹ��մϴ�.
        UE_LOG(LogTemp, Log, TEXT("FFmpeg successfully combined audio files."));
        UE_LOG(LogTemp, Log, TEXT("FFmpeg Output: %s"), *StdOut);
        return true;
    }
    else
    {
        // ������ �߻��ߴٴ� ���� �ǹ��մϴ�.
        UE_LOG(LogTemp, Error, TEXT("FFmpeg failed to combine audio files."));
        UE_LOG(LogTemp, Error, TEXT("FFmpeg StdErr: %s"), *StdErr);
        if (!StdOut.IsEmpty())
        {
            UE_LOG(LogTemp, Log, TEXT("FFmpeg StdOut: %s"), *StdOut);
        }
        return false;
    }
}


bool UMyClass::CombineFinalFiles(const FString& VideoFilePath, const FString& AudioFilePath, const FString& OutputFilePath)
{
    // FFmpeg ���� ������ ��θ� �ùٸ��� �����մϴ�.
    FString FFmpegExecutable = FPaths::Combine(FPaths::ProjectDir(), TEXT("Source/ThirdParty/ffmpeg.exe"));

    // ��� �� �μ��� ������ �����մϴ�.
    FString CommandArgs = FString::Printf(TEXT("-y -i \"%s\" -i \"%s\" -c:v copy -c:a aac -strict experimental \"%s\""),
        *VideoFilePath,
        *AudioFilePath,
        *OutputFilePath);

    // ���� ExecProcess�� ���� ���� ��ο� ��� �μ��� ȣ���մϴ�.
    int32 ReturnCode = 0;
    FString StdOut;
    FString StdErr;
    FPlatformProcess::ExecProcess(*FFmpegExecutable, *CommandArgs, &ReturnCode, &StdOut, &StdErr);

    // ���μ��� ���� ����� Ȯ���մϴ�.
    if (ReturnCode == 0)
    {
        // ���������� ����ƴٴ� ���� �ǹ��մϴ�.
        UE_LOG(LogTemp, Log, TEXT("FFmpeg successfully combined video and audio."));
        UE_LOG(LogTemp, Log, TEXT("FFmpeg Output: %s"), *StdOut); // FFmpeg�� ǥ�� ����� �α׿� ����մϴ�.
        return true;
    }
    else
    {
        // ������ �߻��ߴٴ� ���� �ǹ��մϴ�.
        UE_LOG(LogTemp, Error, TEXT("FFmpeg failed to combine video and audio."));
        UE_LOG(LogTemp, Error, TEXT("FFmpeg StdErr: %s"), *StdErr); // FFmpeg�� ǥ�� ������ �α׿� ����մϴ�.
        if (!StdOut.IsEmpty())
        {
            UE_LOG(LogTemp, Log, TEXT("FFmpeg StdOut: %s"), *StdOut); // FFmpeg�� ǥ�� ����� ���� ���, �̸� �α׿� ����մϴ�.
        }
        return false;
    }
}

TArray<FString> UMyClass::GetWAVFilesFromDirectory(const FString& DirectoryPath)
{
    TArray<FString> WAVFiles;
    IFileManager& FileManager = IFileManager::Get();
    FString Extension = TEXT("*.wav");

    FileManager.FindFiles(WAVFiles, *DirectoryPath, *Extension);

    // ���� ��ο� ���丮 ��θ� �߰��մϴ�.
    for (int32 i = 0; i < WAVFiles.Num(); i++)
    {
        WAVFiles[i] = FPaths::Combine(DirectoryPath, WAVFiles[i]);
    }

    // ���� �̸����� �����մϴ�.
    WAVFiles.Sort([](const FString& A, const FString& B) {
        // ���� �̸����� ���ڸ� �����մϴ�.
        int32 NumA = FCString::Atoi(*FPaths::GetBaseFilename(A));
        int32 NumB = FCString::Atoi(*FPaths::GetBaseFilename(B));
        return NumA < NumB;
        });

    return WAVFiles;
}
