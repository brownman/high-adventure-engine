/*
    High Adventure 3D Game Engine
    Copyright (C) 2002  Rodney Degracia

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

	rodney_degracia(at)elitefrontier.com

	Rodney Degracia
	316 Independence Ave. SE 
	Washington DC 2003
*/

#pragma once

template <typename TSegment>
class MemorySegment
{
	TSegment* m_pMemoryBlock;
	size_t size;

public:

	MemorySegment() : size(), m_pMemoryBlock(0)
	{
	}

	void Create(size_t size)
	{
		assert(m_pMemoryBlock==0);

		m_pMemoryBlock=new TSegment[size];
	}

	void Reclaim()
	{
		delete [] m_pMemoryBlock;
		m_pMemoryBlock=0;
	}

	TSegment* GetStart()
	{
		return m_pMemoryBlock;
	}

	long GetSegmentTypeSize()
	{
		return sizeof(TSegment);
	}
};