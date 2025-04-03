// MyGameInstance.h

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

/**
 * GameInstance Ŭ������ ���� ���ݿ� ���� ���ӵǴ� �����Ϳ� ������ �����մϴ�.
 */
UCLASS()
class FRAMECAPTUREDEMO_API UMyGameInstance : public UGameInstance
{
    GENERATED_BODY()

public:
    // ������
    UMyGameInstance();

    // ���������� Ŭ���� ��ư�� �̸��� �����մϴ�.
    UPROPERTY(BlueprintReadOnly, Category = "Button")
        FString LastClickedButtonName;

    // ĳ���� �̸��� ������ TMap �Դϴ�.
    UPROPERTY()
        TMap<FString, FString> CharacterTTSMap;

    // ĳ���� ���� �̸��� �����ϴ� �����Դϴ�.
    UPROPERTY(BlueprintReadOnly, Category = "Character Slots")
        FString Slot1CharacterName;

    UPROPERTY(BlueprintReadOnly, Category = "Character Slots")
        FString Slot2CharacterName;

    // ĳ���� �̸��� �迭�� �߰��ϴ� �Լ��Դϴ�.
    void AddCharacterName(const FString& CharacterName);

    // ĳ���� �̸� �迭�� �������� �ʱ�ȭ�ϴ� �Լ��Դϴ�.
    TArray<FString> GetAndClearCharacterNames();

    // ���� �̸��� �����ϴ� �Լ��Դϴ�.
    void SetSlot1CharacterName(const FString& NewName);
    void SetSlot2CharacterName(const FString& NewName);

private:
    // ĳ���� �̸��� �߰��ϱ� ���� ���� �迭�Դϴ�.
    TArray<FString> CharacterNamesToBeAdded;
};

