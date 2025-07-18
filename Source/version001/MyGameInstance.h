#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

UCLASS()
class TU_PROYECTO_API UMyGameInstance : public UGameInstance
{
    GENERATED_BODY()

public:

    UFUNCTION(BlueprintCallable)
    void HostGame(FName LevelName);

    UFUNCTION(BlueprintCallable)
    void JoinGame(const FString& IPAddress);
};
