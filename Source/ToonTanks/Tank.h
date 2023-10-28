// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()
	

public:
	ATank();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void HandleDestruction();

	APlayerController* GetPlayerController() { return PlayerController;  }

	bool bAlive = true;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


private:
	UPROPERTY(EditAnywhere, Category = "Camera", meta = (AllowPrivateAcces = "true"))
	class USpringArmComponent* SpringArm;
	UPROPERTY(EditAnywhere, Category = "Camera", meta = (AllowPrivateAcces = "true"))
	class UCameraComponent* Camera;
	UPROPERTY(EditAnywhere, Category = "Movement", meta = (AllowPrivateAcces = "true"))
	float Speed = 100;
	UPROPERTY(EditAnywhere, Category = "Movement")
	float RotatingSpeed = 20;

	void Move(float Value);
	void Turn(float Value);

	APlayerController* PlayerController;

	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
