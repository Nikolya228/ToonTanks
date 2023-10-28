// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();

	void HandleDestruction();

protected:
	void RotateTurret(FVector LookAtTarget);

	void Fire();

private:
	UPROPERTY(EditAnywhere, Category = "Mesh", meta = (AllowPrivateAcces = "true"))
	class UCapsuleComponent* CapsuleComp;
	UPROPERTY(EditAnywhere, Category = "Mesh", meta = (AllowPrivateAcces = "true"))
	UStaticMeshComponent* BaseMesh;
	UPROPERTY(EditAnywhere, Category = "Mesh", meta = (AllowPrivateAcces = "true"))
	UStaticMeshComponent* TurretMesh;
	UPROPERTY(EditAnywhere, Category = "Mesh", meta = (AllowPrivateAcces = "true"))
	USceneComponent* ProjectileSpawnPoint;

	UPROPERTY(EditAnywhere, Category="Attack")
	TSubclassOf<class AProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere)
	float RotateSpeed = 5.f;

	UPROPERTY(EditAnywhere, Category="Particle")
	class UParticleSystem* DeathParticle;

	UPROPERTY(EditAnywhere, Category="Sound")
	class USoundBase* DeathSound;

	UPROPERTY(EditAnywhere, Category="Camera")
	TSubclassOf<class UCameraShakeBase> DeathCameraShake;
};
