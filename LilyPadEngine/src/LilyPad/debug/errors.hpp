#pragma once

namespace LilyPad
{
	enum Error
	{
		OK,
		FAILURE, // Generic error
		ERR_LOAD_TEXTURE_FAILURE,
		ERR_LOAD_SHADER_FAILURE,
		ERR_FILE_NOT_FOUND // 5
	};
} // namespace LilyPad
