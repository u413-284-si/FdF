/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:32:16 by sqiu              #+#    #+#             */
/*   Updated: 2023/03/02 16:37:39 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/events.h"
#include "../inc/window.h"

/* This function handles all keypress events assigning individual actions
to each key being pressed. */

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		joder(data);
	return (0);
}
