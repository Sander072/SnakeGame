#include "SnakeBase.h"
#include "SnakeElementBase.h"

// Sets default values
ASnakeBase::ASnakeBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
<<<<<<< HEAD

	ElementSize = 100.0f;

	MovementSpeed = 0.5f;
	LastMovementDirection = EMovementDirection::RIGHT;
=======
	ElementSize = 100.f;
	MovementSpeed = 10.f;
	LastMoveDirection = EMovementDirection::DOWN;
>>>>>>> fa2da82 (Исправил 7)
}

// Called when the game starts or when spawned
void ASnakeBase::BeginPlay()
{
	Super::BeginPlay();

	AddSnakeElement(4);
	SetActorTickInterval(MovementSpeed);
}

// Called every frame
void ASnakeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

<<<<<<< HEAD
	Move();
=======
	Move(DeltaTime);
>>>>>>> fa2da82 (Исправил 7)
}

void ASnakeBase::AddSnakeElement(int ElementsNum)
{
	for (int i = 0; i < ElementsNum; i++)
	{
		FVector NewLocation(SnakeElements.Num() * ElementSize, 0, 0);
		FTransform NewTransform(NewLocation);
		auto NewSnakeElement = GetWorld()->SpawnActor<ASnakeElementBase>(SnakeElementClass, NewTransform);
		NewSnakeElement->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
<<<<<<< HEAD

=======
>>>>>>> fa2da82 (Исправил 7)
		SnakeElements.Add(NewSnakeElement);
	}
}

<<<<<<< HEAD
void ASnakeBase::Move()
{
	FVector MovementVector = FVector::ZeroVector;
	float MovementSpeedDelta = ElementSize;

	switch (LastMovementDirection)
=======
void ASnakeBase::Move(float DeltaTime)
{
	FVector MovementVector;
	float MovementSpeedDelta = MovementSpeed * DeltaTime;

	switch (LastMoveDirection)
>>>>>>> fa2da82 (Исправил 7)
	{
	case EMovementDirection::UP:
		MovementVector.X += MovementSpeedDelta;
		break;
	case EMovementDirection::DOWN:
		MovementVector.X -= MovementSpeedDelta;
		break;
<<<<<<< HEAD
	case EMovementDirection::RIGHT:
		MovementVector.Y += MovementSpeedDelta;
		break;
	case EMovementDirection::LEFT:
		MovementVector.Y -= MovementSpeedDelta;
		break;
	default:
		break;
	}

	for (int i = SnakeElements.Num() - 1; i > 0; i--)
	{
		auto CurrentElement = SnakeElements[i];
		auto PreviousElement = SnakeElements[i - 1];

		FVector PreviousElementLocation = PreviousElement->GetActorLocation();
		CurrentElement->SetActorLocation(PreviousElementLocation);
	}

	SnakeElements[0]->AddActorWorldOffset(MovementVector);
=======
	case EMovementDirection::LEFT:
		MovementVector.Y -= MovementSpeedDelta;
		break;
	case EMovementDirection::RIGHT:
		MovementVector.Y -= MovementSpeedDelta;
		break;
	}

	AddActorWorldOffset(MovementVector);
>>>>>>> fa2da82 (Исправил 7)
}



