#include "MyClass.h"
#include "Misc/Paths.h"
#include "HAL/PlatformFilemanager.h"
#include "Runtime/Core/Public/Misc/Paths.h"
#include "Runtime/Core/Public/HAL/PlatformProcess.h"

bool UMyClass::CombineMultipleAudioFiles(const TArray<FString>& AudioFilePaths, const FString& OutputFilePath)
{
    // FFmpeg 실행 파일의 경로를 올바르게 결합합니다.
    FString FFmpegExecutable = FPaths::Combine(FPaths::ProjectDir(), TEXT("Source/ThirdParty/ffmpeg.exe"));

    // 입력 파일을 위한 명령 인수를 구성합니다.
    FString InputArgs;
    for (int32 Index = 0; Index < AudioFilePaths.Num(); ++Index)
    {
        InputArgs += FString::Printf(TEXT("-i \"%s\" "), *AudioFilePaths[Index]);
    }

    // filter_complex 인수를 구성합니다.
    FString FilterComplex;
    for (int32 Index = 0; Index < AudioFilePaths.Num(); ++Index)
    {
        FilterComplex += FString::Printf(TEXT("[%d:0]"), Index);
    }
    FilterComplex += FString::Printf(TEXT("concat=n=%d:v=0:a=1[out]"), AudioFilePaths.Num());

    // 명령 줄 인수를 별도로 구성합니다.
// `-y` 플래그를 CommandArgs 시작 부분에 추가합니다.
    FString CommandArgs = FString::Printf(TEXT("-y %s -filter_complex \"%s\" -map \"[out]\" \"%s\""),
        *InputArgs,
        *FilterComplex,
        *OutputFilePath);

    // 이제 ExecProcess를 실행 파일 경로와 명령 인수로 호출합니다.
    int32 ReturnCode = 0;
    FString StdOut;
    FString StdErr;
    FPlatformProcess::ExecProcess(*FFmpegExecutable, *CommandArgs, &ReturnCode, &StdOut, &StdErr);

    // 프로세스 실행 결과를 확인합니다.
    if (ReturnCode == 0)
    {
        // 성공적으로 실행됐다는 것을 의미합니다.
        UE_LOG(LogTemp, Log, TEXT("FFmpeg successfully combined audio files."));
        UE_LOG(LogTemp, Log, TEXT("FFmpeg Output: %s"), *StdOut);
        return true;
    }
    else
    {
        // 오류가 발생했다는 것을 의미합니다.
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
    // FFmpeg 실행 파일의 경로를 올바르게 결합합니다.
    FString FFmpegExecutable = FPaths::Combine(FPaths::ProjectDir(), TEXT("Source/ThirdParty/ffmpeg.exe"));

    // 명령 줄 인수를 별도로 구성합니다.
    FString CommandArgs = FString::Printf(TEXT("-y -i \"%s\" -i \"%s\" -c:v copy -c:a aac -strict experimental \"%s\""),
        *VideoFilePath,
        *AudioFilePath,
        *OutputFilePath);

    // 이제 ExecProcess를 실행 파일 경로와 명령 인수로 호출합니다.
    int32 ReturnCode = 0;
    FString StdOut;
    FString StdErr;
    FPlatformProcess::ExecProcess(*FFmpegExecutable, *CommandArgs, &ReturnCode, &StdOut, &StdErr);

    // 프로세스 실행 결과를 확인합니다.
    if (ReturnCode == 0)
    {
        // 성공적으로 실행됐다는 것을 의미합니다.
        UE_LOG(LogTemp, Log, TEXT("FFmpeg successfully combined video and audio."));
        UE_LOG(LogTemp, Log, TEXT("FFmpeg Output: %s"), *StdOut); // FFmpeg의 표준 출력을 로그에 기록합니다.
        return true;
    }
    else
    {
        // 오류가 발생했다는 것을 의미합니다.
        UE_LOG(LogTemp, Error, TEXT("FFmpeg failed to combine video and audio."));
        UE_LOG(LogTemp, Error, TEXT("FFmpeg StdErr: %s"), *StdErr); // FFmpeg의 표준 에러를 로그에 기록합니다.
        if (!StdOut.IsEmpty())
        {
            UE_LOG(LogTemp, Log, TEXT("FFmpeg StdOut: %s"), *StdOut); // FFmpeg의 표준 출력이 있을 경우, 이를 로그에 기록합니다.
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

    // 파일 경로에 디렉토리 경로를 추가합니다.
    for (int32 i = 0; i < WAVFiles.Num(); i++)
    {
        WAVFiles[i] = FPaths::Combine(DirectoryPath, WAVFiles[i]);
    }

    // 파일 이름으로 정렬합니다.
    WAVFiles.Sort([](const FString& A, const FString& B) {
        // 파일 이름에서 숫자만 추출합니다.
        int32 NumA = FCString::Atoi(*FPaths::GetBaseFilename(A));
        int32 NumB = FCString::Atoi(*FPaths::GetBaseFilename(B));
        return NumA < NumB;
        });

    return WAVFiles;
}
