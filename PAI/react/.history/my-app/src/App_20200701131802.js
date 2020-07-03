import React from 'react';
import './App.css';
import Task from './Task';

function App() {
  return (
    <div className="App">
      <header className="App-header">
        <h1>Welcome to my To Do list!</h1>
        <Task text = "costam" />
        <Task text = "Domi jest spoko"/>
      </header>
    </div>
  );
}

export default App;
