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
		ATank();

public:
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:
	UPROPERTY(VisibleAnywhere, Category = "tank", meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleAnywhere, Category = "tank", meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* Camera;
	UPROPERTY(EditAnywhere, Category = "Movement", meta = (AllowPrivateAccess = "true"))
		float Speed = 200.f;  
	UPROPERTY(EditAnywhere, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	float TurnRate = 45.f;
	UPROPERTY()
		APlayerController* PlayerControllerRef;

	UFUNCTION()
		void MoveForward(float Value);
	UFUNCTION()
		void MoveRight(float Value);

};