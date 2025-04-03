// MyGameInstance.cpp
#include "MyGameInstance.h"

UMyGameInstance::UMyGameInstance()
{
    // ���� �ʱ�ȭ
    Slot1CharacterName = TEXT("");
    Slot2CharacterName = TEXT("");
}

void UMyGameInstance::AddCharacterName(const FString& CharacterName)
{
    if (!CharacterName.IsEmpty())
    {
        CharacterNamesToBeAdded.AddUnique(CharacterName);
    }
}

TArray<FString> UMyGameInstance::GetAndClearCharacterNames()
{
    TArray<FString> Names = CharacterNamesToBeAdded;
    CharacterNamesToBeAdded.Empty();
    return Names;
}

void UMyGameInstance::SetSlot1CharacterName(const FString& NewName)
{
    // ���� ������ ������ �ʱ�ȭ�Ǿ����Ƿ�, �ܼ��� ���� �Ҵ��մϴ�.
    if (!NewName.IsEmpty())
    {
        Slot1CharacterName = NewName;
        // �ʿ��� ��� ���⼭ �޺� �ڽ��� ������Ʈ�ϰų� �ٸ� ���� �۾��� ������ �� �ֽ��ϴ�.
    }
}

void UMyGameInstance::SetSlot2CharacterName(const FString& NewName)
{
    // ���� ������ ������ �ʱ�ȭ�Ǿ����Ƿ�, �ܼ��� ���� �Ҵ��մϴ�.
    if (!NewName.IsEmpty())
    {
        Slot2CharacterName = NewName;
        // �ʿ��� ��� ���⼭ �޺� �ڽ��� ������Ʈ�ϰų� �ٸ� ���� �۾��� ������ �� �ֽ��ϴ�.
    }
}
