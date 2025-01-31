/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 21:00:41 by xazuaje-          #+#    #+#             */
/*   Updated: 2024/12/17 21:57:02 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <intersection.h>
/*
w = ray_origin - cylinder_center
d_perpendicular = ray_direction - (ray_direction · c_axis) * c_axis
w_perpendicular = w - (w · w) * c_axis
discriminant = b² - 4ac
*/

/*// cylinder defined by extremes a and b, and radious ra
vec4 cylIntersect( in vec3 ro, in vec3 rd, in vec3 a, in vec3 b, float ra )
{
    vec3  ba = b  - a;
    vec3  oc = ro - a;
    float baba = dot(ba,ba);
    float bard = dot(ba,rd);
    float baoc = dot(ba,oc);
    float k2 = baba            - bard*bard;
    float k1 = baba*dot(oc,rd) - baoc*bard;
    float k0 = baba*dot(oc,oc) - baoc*baoc - ra*ra*baba;
    float h = k1*k1 - k2*k0;
    if( h<0.0 ) return vec4(-1.0);//no intersection
    h = sqrt(h);
    float t = (-k1-h)/k2;
    // body
    float y = baoc + t*bard;
    if( y>0.0 && y<baba ) return vec4( t, (oc+t*rd - ba*y/baba)/ra );
    // caps
    t = ( ((y<0.0) ? 0.0 : baba) - baoc)/bard;
    if( abs(k1+k2*t)<h )
    {
        return vec4( t, ba*sign(y)/sqrt(baba) );
    }
    return vec4(-1.0);//no intersection
}

// normal at point p of cylinder (a,b,ra), see above     //shading and lightning
vec3 cylNormal( in vec3 p, in vec3 a, in vec3 b, float ra )
{
    vec3  pa = p - a;
    vec3  ba = b - a;
    float baba = dot(ba,ba);
    float paba = dot(pa,ba);
    float h = dot(pa,ba)/baba;
    return (pa - ba*h)/ra;
*/

/*t_vec3	rgb_to_hsl(t_rgba rgb)
{
	float	maxC;
	if (rgb.r >= rgb.g)
		if (rgb.r >= rgb.b)
			maxC = rgb.r;
	if (rgb.g >= rgb.r)
		if (rgb.g >= rgb.b)
			maxC = rgb.g;
	if (rgb.b >= rgb.r)
		if (rgb.b >= rgb.g)
			maxC = rgb.b;
	
	float	minC;
	if (rgb.r <= rgb.g)
		if (rgb.r <= rgb.b)
			minC = rgb.r;
	if (rgb.g <= rgb.r)
		if (rgb.g <= rgb.b)
			minC = rgb.g;
	if (rgb.b <= rgb.r)
		if (rgb.b <= rgb.g)
			minC = rgb.b;

	float	delta = maxC - minC;

	float	h = 0.0;
	if (delta > 0.0)
	{
		if (maxC = rgb.r)
		{
			h = (rgb.g - rgb.b) / delta;
			if (h < 0.0)
				h += 6.0;
		}
		else if (maxC == rgb.g)
			h = (rgb.b - rgb.r) / delta + 2.0;
		else
			h = (rgb.r - rgb.g) / delta + 4.0;
		h /= 6.0;
	}
	
	float	l = (maxC + minC) / 2.0;
	float s = 0.0;
	if (delta > 0.0)
	    s = delta / (1.0 - abs(2.0 * l - 1.0));
	return ((t_vec3){h, s, l})

}

t_vec3	cylinder_normal(t_vec3 point, t_vec3 a_base, t_vec3 b_top, float ra)
{
	t_vec3	pa = substract_vec3(point, a_base);
	t_vec3	ba = substract_vec3(b_top, a_base);

	float	baba = dot_product_vec3(ba, ba);
	float	paba = dot_product_vec3(pa, ba);

	float	h = dot_product_vec3(pa, ba) / baba;

	t_vec3	close_point = add_vec3(a_base, (t_vec3){h * ba.x, h * ba.y, h * ba.z});
	t_vec3	normal = substract_vec3(point, close_point);
	t_vec3	light_dir = normalize_vec3(substract_vec3(light_pos - intersection));

}*/

int cylinder_intersection(t_ray *ray, t_scene_element *elem, int bounce)
{
	t_cylinder	*cy;
	(void)bounce;
	cy = &elem->cylinder;

	t_vec3 b_ctop = add_vec3(cy->coords, (t_vec3){(cy->height / 2) * cy->rotate_vec.x, (cy->height / 2) * cy->rotate_vec.y, (cy->height / 2) * cy->rotate_vec.z});
	t_vec3 a_cbottom = substract_vec3(cy->coords, (t_vec3){(cy->height / 2) * cy->rotate_vec.x, (cy->height / 2) * cy->rotate_vec.y, (cy->height / 2) * cy->rotate_vec.z});

	t_vec3	ba_c_vec_dir = substract_vec3(b_ctop, a_cbottom);
	t_vec3	oc_ro_less_a = substract_vec3(ray->position, a_cbottom);

	float	baba = dot_product_vec3(ba_c_vec_dir, ba_c_vec_dir);
	float	bard = dot_product_vec3(ba_c_vec_dir, ray->normalized);
	float	baoc = dot_product_vec3(ba_c_vec_dir, oc_ro_less_a);

	float	k2 = baba - bard * bard;
	float	k1 = baba * dot_product_vec3(oc_ro_less_a, ray->direction) - baoc * bard;
	float	k0 = baba * dot_product_vec3(oc_ro_less_a, oc_ro_less_a) - baoc * baoc - (cy->diameter / 2) * (cy->diameter / 2) * baba;

	float	h_discriminant = k1 *k1 - k2 * k0;
	if (h_discriminant < 0)
		return (0);
	h_discriminant = sqrt(h_discriminant);

	float	t = (-k1 - h_discriminant) / k2;
	float	y = baoc + t * bard;
	if (y > 0.0 && y < baba)
	{
		ray->rgba.r = cy->rgba.r;
		ray->rgba.g = cy->rgba.g;
		ray->rgba.b = cy->rgba.b;
		ray->rgba.a = 255;
		return (1); //change vec4( t, (oc+t*rd - ba*y/baba)/ra )
	}
	if (y < 0.0)
    	t = (0.0 - baoc) / bard;
	else
    	t = (baba - baoc) / bard;

	if (fabs(k1 + k2 * t) < h_discriminant)
	{
		ray->rgba.r = cy->rgba.r;
		ray->rgba.g = cy->rgba.g;
		ray->rgba.b = cy->rgba.b;
		ray->rgba.a = 255;
		return (1); //vec4( t, ba*sign(y)/sqrt(baba) )
	}
	return (0);
}

/*int cylinder_intersection(t_ray ray, t_scene_element *elem, int bounce)
{
	t_cylinder *cy;
	(void)bounce;
	cy = &elem->cylinder;

	t_vec3	w = substract_vec3(ray->position, cy->coords);
	float	d_o_a = dot_product_vec3(ray->normalized, cy->rotate_vec);
	t_vec3	d_perpendicular = substract_vec3(ray.normalized, (t_vec3){cy->rotate_vec.x * d_o_a, cy->rotate_vec.y * d_o_a, cy->rotate_vec.z * d_o_a});
	float	w_o_a = dot_product_vec3(w, cy->rotate_vec);
	t_vec3	w_perpendicular = substract_vec3(w, (t_vec3){cy->rotate_vec.x * w_o_a, cy->rotate_vec.y * w_o_a, cy->rotate_vec.z * w_o_a});

	float	a = dot_product_vec3(d_perpendicular, d_perpendicular);
	float	b = 2 * dot_product_vec3(w_perpendicular, d_perpendicular);
	float	c = dot_product_vec3(w_perpendicular, w_perpendicular) - ((cy->diameter / 2) * (cy->diameter / 2));

	float	discriminant = (b * b) - (4.0 * (a * c));

	if (discriminant < 0 || a == 0)
		return (0);
	
	float	t1 = ((-b) - (sqrt(discriminant))) / (2.0 * a);
	float	t2 = ((-b) + (sqrt(discriminant))) / (2.0 * a);

	//if (t1 < 0 && t2 < 0)
	//	return (0);

	t_vec3	p1 = add_vec3(ray.position, (t_vec3){t1 * ray.normalized.x, t1 * ray.normalized.y, t1 * ray.normalized.z});
	t_vec3	p2 = add_vec3(ray.position, (t_vec3){t2 * ray.normalized.x, t2 * ray.normalized.y, t2 * ray.normalized.z});

	(void)p1;
	(void)p2;

	//float	h1 = dot_product_vec3(substract_vec3(p1, cy->coords), cy->rotate_vec);
	//float	h2 = dot_product_vec3(substract_vec3(p2, cy->coords), cy->rotate_vec);
	float	o_less_c_o_a = dot_product_vec3(substract_vec3(ray.position, cy->coords), cy->rotate_vec);
	float	h1 = o_less_c_o_a + t1 * dot_product_vec3(ray.normalized, cy->rotate_vec);
	float	h2 = o_less_c_o_a + t2 * dot_product_vec3(ray.normalized, cy->rotate_vec);
	if ((h1 > (-(cy->height / 2)) && h1 < (cy->height / 2)) || (h2 > (-(cy->height / 2)) && h2 < (cy->height / 2)))
		return (1);
	return (0);
}*/
