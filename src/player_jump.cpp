#include "player.hpp"

void Player::jump() {
	// if (!isOnGround)
	// 	return;
	if (isOnGround && !isJumping) {
		isOnGround = false;
		isJumping = true;
		jumpStartTime = std::chrono::steady_clock::now();
		jumpSpeed = -JUMP_SPEED;
		maxJumpHeightReached = false;
		jumpTopReached = false;
	}
	initialY = player.getPosition().y;
	if (isJumping) {
		auto now = std::chrono::steady_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - jumpStartTime).count() / 1000.0;
		// Calculate the player's new position based on the elapsed time and jump speed
		double newY = initialY + jumpHeight;

		// Check if the player has reached the maximum jump height
		if (jumpHeight <= -MAX_JUMP_HEIGHT) {
			maxJumpHeightReached = true;
			jumpSpeed = 0;
		}
		// Check if the player has reached the top of the jump
		if (jumpSpeed <= 0 && !jumpTopReached) {
			jumpTopReached = true;
		}
		// Update the player's position
		// setPos(player.getPosition().x, newY);

		// Update the jump speed based on the elapsed time and gravity
		jumpSpeed = jumpSpeed + GRAVITY * elapsed;
		player.move(0, -1);
		isOnGround = false;
	}
}