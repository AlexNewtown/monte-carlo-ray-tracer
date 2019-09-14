#pragma once

#include <memory>

#include <glm/glm.hpp>
#include <glm/vec3.hpp>

class Ray
{
public:
	Ray(const glm::dvec3& start, const glm::dvec3& end)
		: start(start), end(end), direction(glm::normalize(end - start)) { }

	glm::dvec3 operator()(double t) const
	{
		return start + direction * t;
	}
	
	// Normalized direction -> t corresponds to euclidian distance in metric units
	glm::dvec3 start, end, direction;
};

struct Intersection
{
	glm::dvec3 position;
	glm::dvec3 normal;
	double t = std::numeric_limits<double>::max();

	explicit operator bool() const
	{
		return t != std::numeric_limits<double>::max();
	}
};