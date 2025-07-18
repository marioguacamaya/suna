#include "MyCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "GameFramework/PlayerController.h"
#include "Net/UnrealNetwork.h"

AMyCharacter::AMyCharacter()
{
    bReplicates = true;
    SetReplicatingMovement(true);
    PrimaryActorTick.bCanEverTick = true;
}

void AMyCharacter::BeginPlay()
{
    Super::BeginPlay();

    if (APlayerController* PC = Cast<APlayerController>(Controller))
    {
        if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
            ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
        {
            if (InputMapping)
            {
                Subsystem->AddMappingContext(InputMapping, 0);
            }
        }
    }
}

void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    if (UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent))
    {
        if (MoveAction)
            Input->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMyCharacter::Move);
        if (LookAction)
            Input->BindAction(LookAction, ETriggerEvent::Triggered, this, &AMyCharacter::Look);
        if (FireAction)
            Input->BindAction(FireAction, ETriggerEvent::Started, this, &AMyCharacter::Fire);
    }
}

void AMyCharacter::Move(const FInputActionValue& Value)
{
    const FVector2D MoveVector = Value.Get<FVector2D>();
    if (Controller)
    {
        AddMovementInput(GetActorForwardVector(), MoveVector.Y);
        AddMovementInput(GetActorRightVector(), MoveVector.X);
    }
}

void AMyCharacter::Look(const FInputActionValue& Value)
{
    const FVector2D LookAxis = Value.Get<FVector2D>();
    if (Controller)
    {
        AddControllerYawInput(LookAxis.X);
        AddControllerPitchInput(LookAxis.Y);
    }
}

void AMyCharacter::Fire()
{
    if (HasAuthority())
    {
        // lógica de disparo en servidor
    }
    else
    {
        ServerFire();
    }
}

void AMyCharacter::ServerFire_Implementation()
{
    Fire(); // Ejecuta disparo en servidor
}
