// Copyright 2010 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_PICTURE_IMAGE_LAYER_H_
#define CC_PICTURE_IMAGE_LAYER_H_

#include "cc/cc_export.h"
#include "cc/content_layer_client.h"
#include "cc/picture_layer.h"
#include "third_party/skia/include/core/SkBitmap.h"
#include "ui/gfx/size.h"

namespace cc {

class CC_EXPORT PictureImageLayer : public PictureLayer, ContentLayerClient {
 public:
  static scoped_refptr<PictureImageLayer> Create();

  void SetBitmap(const SkBitmap& image);

  // Layer implementation.
  virtual scoped_ptr<LayerImpl> CreateLayerImpl(
      LayerTreeImpl* tree_impl) OVERRIDE;
  virtual bool DrawsContent() const OVERRIDE;

  // ContentLayerClient implementation.
  virtual void PaintContents(
      SkCanvas* canvas,
      gfx::Rect clip,
      gfx::RectF* opaque) OVERRIDE;

 private:
  PictureImageLayer();
  virtual ~PictureImageLayer();

  SkBitmap bitmap_;
};

}  // namespace cc

#endif  // CC_PICTURE_IMAGE_LAYER_H_
