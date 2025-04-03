using UnrealBuildTool;
using System.IO;

public class FrameCaptureDemo : ModuleRules
{

    public FrameCaptureDemo(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "HTTP", "Json", "JsonUtilities", "UMG", "Slate", "SlateCore" });

        string OpenCVPath = Target.RelativeEnginePath + "/Plugins/Marketplace/FrameCapture/Source/ThirdParty/OpenCV/Libraries/Win64";

        LoadFFMPEG(Target);

    }

    private string ThirdPartyPath
    {
        get { return Path.GetFullPath(Path.Combine(ModuleDirectory, "../../Source/ThirdParty/")); }
    }

    public bool LoadFFMPEG(ReadOnlyTargetRules Target)
    {
        bool isLibrarySupported = false;

        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            isLibrarySupported = true;

            string LibrariesPath = Path.Combine(ThirdPartyPath, "ffmpeg", "lib", "vs", "x64");

            PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "avcodec.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "avformat.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "avutil.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "swresample.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "swscale.lib"));
        }

        if (isLibrarySupported)
        {
            // Include path
            PublicIncludePaths.Add(Path.Combine(ThirdPartyPath, "ffmpeg", "include"));
        }

        PublicDefinitions.Add(string.Format("WITH_FFMPEG_BINDING={0}", isLibrarySupported ? 1 : 0));

        return isLibrarySupported;
    }


}
