// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawnBase.h"
#include "Engine/Classes/Camera/CameraComponent.h"
#include "SnakeBase.h"
#include "Components/InputComponent.h"

// Sets default values
APlayerPawnBase::APlayerPawnBase()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PawnCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PawnCamera"));
	RootComponent = PawnCamera;
}

// Called when the game starts or when spawned
void APlayerPawnBase::BeginPlay()
{
	Super::BeginPlay();

	SetActorRotation(FRotator(-90, 0, 0));
	CreateSnakeActor();
}

// Called every frame
void APlayerPawnBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerPawnBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Up", this, &APlayerPawnBase::HandlePlayerUpInput);
	PlayerInputComponent->BindAxis("Right", this, &APlayerPawnBase::HandlePlayerRightInput);
}

void APlayerPawnBase::CreateSnakeActor()
{
	SnakeActor = GetWorld()->SpawnActor<ASnakeBase>(SnakeActorClass, FTransform());
}

void APlayerPawnBase::HandlePlayerUpInput(float value)
{
	if (IsValid(SnakeActor))
	{
		EMovementDirection& LastMovementDirection = SnakeActor->LastMovementDirection;
		if (value > 0 && LastMovementDirection != EMovementDirection::DOWN)
		{
			LastMovementDirection = EMovementDirection::UP;
		}
		else if (value < 0 && LastMovementDirection != EMovementDirection::UP)
		{
			LastMovementDirection = EMovementDirection::DOWN;
		}
	}
}

void APlayerPawnBase::HandlePlayerRightInput(float value)
{
	if (IsValid(SnakeActor))
	{
		EMovementDirection& LastMovementDirection = SnakeActor->LastMovementDirection;
		if (value > 0 && LastMovementDirection != EMovementDirection::LEFT)
		{
			LastMovementDirection = EMovementDirection::RIGHT;
		}
		else if (value < 0 && LastMovementDirection != EMovementDirection::RIGHT)
		{
			LastMovementDirection = EMovementDirection::LEFT;
		}
	}
}



