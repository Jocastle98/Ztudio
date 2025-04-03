using UnrealBuildTool;
using System.Collections.Generic;

public class FrameCaptureDemoEditorTarget : TargetRules
{
    public FrameCaptureDemoEditorTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Editor;

        DefaultBuildSettings = BuildSettingsVersion.V2;

        // 이 배열에 게임 모듈 이름 추가
        ExtraModuleNames.AddRange(new string[] { "FrameCaptureDemo" });
    }
}
