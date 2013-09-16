/*
 *
 * Confidential Information of Telekinesys Research Limited (t/a Havok). Not for disclosure or distribution without Havok's
 * prior written consent. This software contains code, techniques and know-how which is confidential and proprietary to Havok.
 * Product and Trade Secret source code contains trade secrets of Havok. Havok Software (C) Copyright 1999-2013 Telekinesys Research Limited t/a Havok. All Rights Reserved. Use of this software is subject to the terms of an end user license agreement.
 *
 */

#ifndef HK_MORPHING_DEFORMER_H
#define HK_MORPHING_DEFORMER_H

#include <Animation/Animation/Deform/hkaVertexDeformerInput.h>

class hkxVertexBuffer;

/// The abstract base class for weighted vertex deformation.
/// Applies to both indexed and non indexed skinning.
class hkaMorphingDeformer
{
	//+hk.MemoryTracker(ignore=True)
	public:
		virtual ~hkaMorphingDeformer() { }

			/// Bind this deformer to input and output buffers.
			/// The output buffer should be preallocated.
			/// Returns false if the deformer does not support the input or output buffer format.
		hkBool bind( const hkaVertexDeformerInput& input, const hkxVertexBuffer* inputBuffer1, const hkxVertexBuffer* inputBuffer2,  hkxVertexBuffer* outputBuffer );

			/// Interpolate the input buffers into the output buffer.
			/// The deformer must first be bound and the output buffer locked before deforming.
		virtual void deform ( hkReal delta ) = 0;

};

#endif // HK_SKINNING_DEFORMER_H

/*
 * Havok SDK - NO SOURCE PC DOWNLOAD, BUILD(#20130718)
 * 
 * Confidential Information of Havok.  (C) Copyright 1999-2013
 * Telekinesys Research Limited t/a Havok. All Rights Reserved. The Havok
 * Logo, and the Havok buzzsaw logo are trademarks of Havok.  Title, ownership
 * rights, and intellectual property rights in the Havok software remain in
 * Havok and/or its suppliers.
 * 
 * Use of this software for evaluation purposes is subject to and indicates
 * acceptance of the End User licence Agreement for this product. A copy of
 * the license is included with this software and is also available at www.havok.com/tryhavok.
 * 
 */
