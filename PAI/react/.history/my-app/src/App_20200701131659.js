import React from 'react';
import './App.css';
import Task from './Task';

function App(props) {
  return (
    <div className="App">
      <header className="App-header">
        <h1>Welcome to my To Do list!</h1>
        <Task/>
        <Task/>
      </header>
    </div>
  );
}

export default App;
