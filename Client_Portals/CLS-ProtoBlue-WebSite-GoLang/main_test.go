/**
 * www.ProtoBlue.com/
 * (distrubution) main_test.go
 * --------------------------------
 * Created by Lance T. Walker on 11/12/2018
 * Copyright © 2018 CodeLife Productions. All rights reserved.
 */

package main

/* Setup: Frameworks */
import(
  // native:
  "net/http"
  "net/http/httptest"
  "io/ioutil"
  "testing"
);

/* Functions: Main */
func testHandler(t *testing.T) {
  req, err := testNewHandler("GET", "", "");
  checkTestForError(err, t);

  recorder := httptest.NewRecorder();
  hf := http.HandlerFunc(handler);
  hf.ServeHTTP(recorder, req);

  checkTestForErrorComp(recorder.Code, http.StatusOK, "testHandler: unexpected code: ", t);
  checkTestForErrorComp(recorder.Body.String(), "/", "testHandler: unexpected body: ", t);
}

func testRouter(t *testing.T) {
  r := newRouter();
  mockServer := httptest.NewServer(r);
  resp, err := http.Get(mockServer.URL + "/");
  checkTestForError(err, t);

  checkTestForErrorComp(resp.StatusCode, http.StatusOK, "testRouter: status code ", t);

  defer resp.Body.Close();
  b, err := ioutil.ReadAll(resp.Body);
  checkTestForError(err, t);

  respString := string(b);
  expected := "/";

  checkTestForErrorComp(string(b), "/", "testRouter: body ", t);
}

/* Functions: Availability */
func testCheckForHandler(t *testing.T) {

}

func testCheckForRoute(t *testing.T) {
  r := newRouter();
  mockServer := httptest.NewServer(r);

  resp, err := http.Post(mockServer.URL+"/", "", nil);
  checkTestForError(err, t);

  checkTestForErrorComp(resp.StatusCode, http.StatusMethodNotAllowed, "routerCheck: response ", t);

  defer resp.Body.Close();
  b, err := ioutil.ReadAll(resp.Body);
  checkTestForError(err, t);

  checkTestForErrorComp(string(b), "", "routerCheck: response ", t);
}

/* Functions: Types */
func testNewHandler(method, body, query string) (http) {
  return http.NewRequest(method, body, nil);
}

func testNewRouter() (httptest.NewServer) {
  r := newRouter();
  return httptest.NewServer(r);
}

/* Functions: Errors */
func checkTestForError(x error, ext *testing.T) { if x != nil { ext.Fatal(x); } }

func checkTestForErrorComp(a, b int, x string, ext *testing.T) {
  if a != b {
    ext.Errorf("%s %v, expected: %v", x, a, b);
  }
}
