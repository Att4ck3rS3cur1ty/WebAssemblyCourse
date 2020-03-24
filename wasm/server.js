// Express
const express = require('express')
const app = express()

// Server static files from /public
app.use(express.static('public'))

// If you're using older express.js version, it could throw a "mime type" error
// when loading .WASM. Do the following to fix it:
/*
app.use(express.static('public', {
  setHeaders: (res, path, stat) => {
    // Serve .wasm files with correct mime type
    if(path.endsWith('.wasm')) {
      res.set('Content-Type', 'application/wasm')
    }
  }
}))
*/

// Start Server
app.listen(2222, () => console.log('Server running on port 2222.'))
