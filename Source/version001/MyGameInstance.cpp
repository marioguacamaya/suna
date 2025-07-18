#include "MyGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/Engine.h"

void UMyGameInstance::HostGame(FName LevelName)
{
    if (!LevelName.IsNone())
    {
        FString Command = LevelName.ToString() + "?listen";
        UGameplayStatics::OpenLevel(GetWorld(), LevelName, true, "?listen");
    }
}

void UMyGameInstance::JoinGame(const FString& IPAddress)
{
    if (!IPAddress.IsEmpty())
    {
        FString Command = FString::Printf(TEXT("open %s"), *IPAddress);
        if (APlayerController* PC = GetFirstLocalPlayerController())
        {
            PC->ConsoleCommand(Command);
        }
    }
}
