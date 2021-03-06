// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

var embedder = null;

function reportConnected() {
  var msg = ['connected'];
  embedder.postMessage(JSON.stringify(msg), '*');
}

window.addEventListener('message', function(e) {
  embedder = e.source;
  var data = JSON.parse(e.data);
  switch (data[0]) {
    case 'connect': {
      reportConnected();
      break;
    }
  }
});

window.addEventListener('resize', function(e) {
  if (!embedder) {
    return;
  }
  var msg = ['resize', document.body.clientWidth, document.body.clientHeight];
  embedder.postMessage(JSON.stringify(msg), '*');
});
